#include <stdio.h>
#include "zlog.h"

int main(void)
{
    int ret;
	int d=10;
    char *s="world";
	ret = dzlog_init("myzlog.conf", "myrule_class"); //指定配置文件路径及类型名 初始化zlog
	if (ret) 
	{
		printf("init failed\n");
		return -1;
	}
									//打印等级数值越低，等级越高
 	dzlog_debug("debug"); 			//5
	dzlog_info("info,  %d %s",d,s); //4
	dzlog_notice("notice");			//3
	dzlog_warn("warn"); 			//2
	dzlog_error("error");			//1
	dzlog_fatal("fatal");			//0

	zlog_fini();  	//释放zlog
    return 0;
}