
struct payload {
	char * type;
	char * host_name;
	char * service_description;
	char * json_buf;
	char hashed_keys[382];
	char use_hash;
	size_t buflen, bufused;
	char keep_auxdata;
};

struct payload * payload_new();
void adjust_payload_len(struct payload * po, size_t len);
int payload_add_key(struct payload * po, char * key);
void payload_hash_key(struct payload * po, const char * key);
void payload_new_string(struct payload * po, char * key, char * val);
void payload_new_integer(struct payload * po, char * key, long long val);
void payload_new_double(struct payload * po, char * key, double val);
void payload_new_timestamp(struct payload * po,
	char* key, struct timeval * tv);
void payload_new_boolean(struct payload * po, char * key, int val);
void payload_finalize(struct payload * po);
int payload_start_array(struct payload * po, char * key);
void payload_end_array(struct payload * po);
int payload_start_object(struct payload * po, char * key);
void payload_end_object(struct payload * po);
int payload_has_keys(struct payload * po, ...);
