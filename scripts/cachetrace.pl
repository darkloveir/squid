#!/usr/local/bin/perl

require 'sys/socket.ph';

$url = shift || die "usage: $0: url\n";
$host = 'localhost';
$port = 3128;

$url = "http://$url/" if ($url =~ /^[-\w\.]+$/);
print "Querying cache path to $url\n";
$host = $1 if ($url =~ /^[^:]+:\/\/([^\/:])+/);

$sockaddr = 'S n a4 x8';
($name, $aliases, $proto) = getprotobyname("tcp");
($fqdn, $aliases, $type, $len, $thataddr) = gethostbyname($host);
$thissock = pack($sockaddr, &AF_INET, 0, "\0\0\0\0");
$that = pack($sockaddr, &AF_INET, $port, $thataddr);

&try_http_11($url);


sub try_http_11 {
	local($url) = @_;
	local($path) = undef;

	$source = $1 if ($url =~ /^[^:]+:\/\/([^:\/]+)/);
	
	die "socket: $!\n" unless
                socket (SOCK, &AF_INET, &SOCK_STREAM, $proto);
        die "bind: $!\n" unless
                bind (SOCK, $thissock);
        die "$host:$port: $!\n" unless
                connect (SOCK, $that);
        select (SOCK); $| = 1;
        select (STDOUT);
	print SOCK "TRACE $url HTTP/1.1\r\nHost: $host\r\nAccept: */*\r\n\r\n";
	while (<SOCK>) {
		s/\r//g;
		s/\n//g;
		$code = $1 if (/^HTTP\/\d\.\d (\d+)/);
		$server = $1 if (/^Server:\s*(.*)$/);
		$path = $1 if (/^Via:\s*(.*)$/);
	}
	return 0 unless ($path && $code == 200);
	print "Received TRACE reply from $source\n";
	@F = split(',', $path);
	$i = 0;
	foreach $n (@F) {
		$n =~ s/^\s+//;
		printf " %2d   %s\n", ++$i, $n;
	}
	printf " %2d   %s (%s)\n", ++$i, $source, $server;
	1;
}
