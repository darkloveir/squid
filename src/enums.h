

typedef enum {
    LOG_TAG_NONE,
    LOG_TCP_HIT,
    LOG_TCP_MISS,
    LOG_TCP_REFRESH_HIT,
    LOG_TCP_REFRESH_FAIL_HIT,
    LOG_TCP_REFRESH_MISS,
    LOG_TCP_CLIENT_REFRESH,
    LOG_TCP_IMS_HIT,
    LOG_TCP_IMS_MISS,
    LOG_TCP_SWAPFAIL_MISS,
    LOG_TCP_NEGATIVE_HIT,
    LOG_TCP_MEM_HIT,
    LOG_TCP_DENIED,
    LOG_UDP_HIT,
    LOG_UDP_HIT_OBJ,
    LOG_UDP_MISS,
    LOG_UDP_DENIED,
    LOG_UDP_INVALID,
    LOG_UDP_MISS_NOFETCH,
    LOG_TYPE_MAX
} log_type;

typedef enum {
    ERR_NONE,
    ERR_READ_TIMEOUT,
    ERR_LIFETIME_EXP,
    ERR_READ_ERROR,
    ERR_WRITE_ERROR,
    ERR_CLIENT_ABORT,
    ERR_CONNECT_FAIL,
    ERR_INVALID_REQ,
    ERR_UNSUP_REQ,
    ERR_INVALID_URL,
    ERR_SOCKET_FAILURE,
    ERR_DNS_FAIL,
    ERR_CANNOT_FORWARD,
    ERR_NO_RELAY,
    ERR_ZERO_SIZE_OBJECT,
    ERR_FTP_DISABLED,
    ERR_FTP_FAILURE,
    ERR_URN_RESOLVE,
    ERR_ACCESS_DENIED,
    ERR_MAX
} err_type;

typedef enum {
    ACL_NONE,
    ACL_SRC_IP,
    ACL_DST_IP,
    ACL_SRC_DOMAIN,
    ACL_DST_DOMAIN,
    ACL_TIME,
    ACL_URLPATH_REGEX,
    ACL_URL_REGEX,
    ACL_URL_PORT,
    ACL_USER,
    ACL_PROTO,
    ACL_METHOD,
    ACL_BROWSER,
    ACL_PROXY_AUTH,
    ACL_SRC_ASN,
    ACL_DST_ASN,
    ACL_SRC_ARP,
    ACL_ENUM_MAX
} squid_acl;

typedef enum {
    ACL_LOOKUP_NONE,
    ACL_LOOKUP_NEEDED,
    ACL_LOOKUP_PENDING,
    ACL_LOOKUP_DONE
} acl_lookup_state;

typedef enum {
    IP_ALLOW,
    IP_DENY
} ip_access_type;

enum {
    FD_NONE,
    FD_LOG,
    FD_FILE,
    FD_SOCKET,
    FD_PIPE,
    FD_UNKNOWN
};

enum {
    FD_READ,
    FD_WRITE
};

enum {
    FD_CLOSE,
    FD_OPEN
};

enum {
    FQDN_CACHED,
    FQDN_NEGATIVE_CACHED,
    FQDN_PENDING,		/* waiting to be dispatched */
    FQDN_DISPATCHED		/* waiting for reply from dnsserver */
};
typedef unsigned int fqdncache_status_t;

enum {
    IP_CACHED,
    IP_NEGATIVE_CACHED,
    IP_PENDING,			/* waiting to be dispatched */
    IP_DISPATCHED		/* waiting for reply from dnsserver */
};
typedef unsigned int ipcache_status_t;

typedef enum {
    PEER_NONE,
    PEER_SIBLING,
    PEER_PARENT,
    PEER_MULTICAST
} peer_t;

typedef enum {
    MGR_NONE,
    MGR_CLIENT_LIST,
    MGR_CONFIGURATION,
    MGR_DNSSERVERS,
    MGR_FILEDESCRIPTORS,
    MGR_FQDNCACHE,
    MGR_INFO,
    MGR_IO,
    MGR_IPCACHE,
    MGR_LOG_CLEAR,
    MGR_LOG_DISABLE,
    MGR_LOG_ENABLE,
    MGR_LOG_STATUS,
    MGR_LOG_VIEW,
    MGR_NETDB,
    MGR_OBJECTS,
    MGR_REDIRECTORS,
    MGR_REFRESH,
    MGR_REMOVE,
    MGR_REPLY_HDRS,
    MGR_SERVER_LIST,
    MGR_NON_PEERS,
    MGR_SHUTDOWN,
    MGR_UTILIZATION,
    MGR_VM_OBJECTS,
    MGR_STOREDIR,
    MGR_CBDATA,
    MGR_PCONN,
    MGR_5MIN,
    MGR_MAX
} objcache_op;

typedef enum {
    HIER_NONE,
    DIRECT,
    SIBLING_HIT,
    PARENT_HIT,
    DEFAULT_PARENT,
    SINGLE_PARENT,
    FIRSTUP_PARENT,
    NO_PARENT_DIRECT,
    FIRST_PARENT_MISS,
    CLOSEST_PARENT_MISS,
    CLOSEST_DIRECT,
    NO_DIRECT_FAIL,
    SOURCE_FASTEST,
    SIBLING_UDP_HIT_OBJ,
    PARENT_UDP_HIT_OBJ,
    ROUNDROBIN_PARENT,
    HIER_MAX
} hier_code;

typedef enum {
    ICP_INVALID,
    ICP_QUERY,
    ICP_HIT,
    ICP_MISS,
    ICP_ERR,
    ICP_SEND,
    ICP_SENDA,
    ICP_DATABEG,
    ICP_DATA,
    ICP_DATAEND,
    ICP_SECHO,
    ICP_DECHO,
    ICP_UNUSED12,
    ICP_UNUSED13,
    ICP_UNUSED14,
    ICP_UNUSED15,
    ICP_UNUSED16,
    ICP_UNUSED17,
    ICP_UNUSED18,
    ICP_UNUSED19,
    ICP_UNUSED20,
    ICP_MISS_NOFETCH,
    ICP_DENIED,
    ICP_HIT_OBJ,
    ICP_END
} icp_opcode;

enum {
    NOT_IN_MEMORY,
    IN_MEMORY
};

enum {
    PING_NONE,
    PING_WAITING,
    PING_TIMEOUT,
    PING_DONE
};

enum {
    STORE_OK,
    STORE_PENDING,
    STORE_ABORTED
};

enum {
    SWAPOUT_NONE,
    SWAPOUT_OPENING,
    SWAPOUT_WRITING,
    SWAPOUT_DONE
};

enum {
    STORE_NON_CLIENT,
    STORE_MEM_CLIENT,
    STORE_DISK_CLIENT
};

enum {
    METHOD_NONE,		/* 000 */
    METHOD_GET,			/* 001 */
    METHOD_POST,		/* 010 */
    METHOD_PUT,			/* 011 */
    METHOD_HEAD,		/* 100 */
    METHOD_CONNECT,		/* 101 */
    METHOD_TRACE,		/* 110 */
    METHOD_PURGE		/* 111 */
};
typedef unsigned int method_t;

typedef enum {
    PROTO_NONE,
    PROTO_HTTP,
    PROTO_FTP,
    PROTO_GOPHER,
    PROTO_WAIS,
    PROTO_CACHEOBJ,
    PROTO_ICP,
    PROTO_URN,
    PROTO_MAX
} protocol_t;

typedef enum {
    HTTP_CONTINUE = 100,
    HTTP_SWITCHING_PROTOCOLS = 101,
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_ACCEPTED = 202,
    HTTP_NON_AUTHORITATIVE_INFORMATION = 203,
    HTTP_NO_CONTENT = 204,
    HTTP_RESET_CONTENT = 205,
    HTTP_PARTIAL_CONTENT = 206,
    HTTP_MULTIPLE_CHOICES = 300,
    HTTP_MOVED_PERMANENTLY = 301,
    HTTP_MOVED_TEMPORARILY = 302,
    HTTP_SEE_OTHER = 303,
    HTTP_NOT_MODIFIED = 304,
    HTTP_USE_PROXY = 305,
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_PAYMENT_REQUIRED = 402,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_METHOD_NOT_ALLOWED = 405,
    HTTP_NOT_ACCEPTABLE = 406,
    HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
    HTTP_REQUEST_TIMEOUT = 408,
    HTTP_CONFLICT = 409,
    HTTP_GONE = 410,
    HTTP_LENGTH_REQUIRED = 411,
    HTTP_PRECONDITION_FAILED = 412,
    HTTP_REQUEST_ENTITY_TOO_LARGE = 413,
    HTTP_REQUEST_URI_TOO_LARGE = 414,
    HTTP_UNSUPPORTED_MEDIA_TYPE = 415,
    HTTP_INTERNAL_SERVER_ERROR = 500,
    HTTP_NOT_IMPLEMENTED = 501,
    HTTP_BAD_GATEWAY = 502,
    HTTP_SERVICE_UNAVAILABLE = 503,
    HTTP_GATEWAY_TIMEOUT = 504,
    HTTP_HTTP_VERSION_NOT_SUPPORTED = 505
} http_status;

/* These are for StoreEntry->flag, which is defined as a SHORT */
enum {
    ENTRY_SPECIAL,
    ENTRY_REVALIDATE,
    DELAY_SENDING,
    RELEASE_REQUEST,
    REFRESH_REQUEST,
    ENTRY_CACHABLE,
    ENTRY_DISPATCHED,
    KEY_PRIVATE,
    HIERARCHICAL,
    ENTRY_NEGCACHED,
    ENTRY_VALIDATED
};

enum {
    HTTP_PROXYING,
    HTTP_KEEPALIVE
};

enum {
    ERR_FLAG_CBDATA
};

enum {
    REQ_RANGE,
    REQ_NOCACHE,
    REQ_IMS,
    REQ_AUTH,
    REQ_CACHABLE,
    REQ_UNUSED05,
    REQ_HIERARCHICAL,
    REQ_LOOPDETECT,
    REQ_PROXY_KEEPALIVE,
    REQ_PROXYING,
    REQ_REFRESH,
    REQ_USED_PROXY_AUTH
};

enum {
    FD_CLOSE_REQUEST,
    FD_WRITE_DAEMON,
    FD_WRITE_PENDING,
    FD_CLOSING,
    FD_SOCKET_EOF
};

enum {
    HELPER_ALIVE,
    HELPER_BUSY,
    HELPER_CLOSING,
    HELPER_SHUTDOWN
};

enum {
    NEIGHBOR_PROXY_ONLY,
    NEIGHBOR_NO_QUERY,
    NEIGHBOR_DEFAULT_PARENT,
    NEIGHBOR_ROUNDROBIN,
    NEIGHBOR_MCAST_RESPONDER,
    NEIGHBOR_CLOSEST_ONLY
};

typedef enum {
    ACCESS_DENIED,
    ACCESS_ALLOWED,
    ACCESS_REQ_PROXY_AUTH
} allow_t;

enum {
    SNMP_C_VIEW,
    SNMP_C_USER,
    SNMP_C_COMMUNITY
};
