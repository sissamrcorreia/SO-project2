#define MAX_RESERVATION_SIZE 256
#define STATE_ACCESS_DELAY_US 500000  // 500ms
#define MAX_JOB_FILE_NAME_SIZE 256
#define MAX_SESSION_COUNT 8


typedef struct sessions {
  int session_id;
  char* req_pipe_path;
  char* resp_pipe_path;
} sessions_t;