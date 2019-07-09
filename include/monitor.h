#ifndef _MONITOR_H_
#define _MONITOR_H_

typedef union
{
    INT64 i64;
    INT32 i32;
    UINT64 u64;
    UINT32 u32;
} t_num;

 typedef struct {
          char	cmd[12];
          void	(*func_ptr)(int argc, char *argv[]);
          char	description[60];
} CMD_LIST;

#endif /* _MONITOR_H_ */
