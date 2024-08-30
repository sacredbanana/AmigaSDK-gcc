/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SQLITE_H
#define _PPCINLINE_SQLITE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SQLITE_BASE_NAME
#define SQLITE_BASE_NAME SQLiteBase
#endif /* !SQLITE_BASE_NAME */

#define sqlite3_create_function_v2(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		void (* __t__p5)(sqlite3_context*,int,sqlite3_value**) = __p5;\
		void (* __t__p6)(sqlite3_context*,int,sqlite3_value**) = __p6;\
		void (* __t__p7)(sqlite3_context*) = __p7;\
		void (* __t__p8)(void*)  = __p8;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , int , void *, void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*), void (*)(void*) ))*(void**)(__base - 610))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define sqlite3_open(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		sqlite3 ** __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, sqlite3 **))*(void**)(__base - 256))(__t__p0, __t__p1));\
	})

#define sqlite3_busy_handler(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int (* __t__p1)(void*,int) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int (*)(void*,int), void *))*(void**)(__base - 160))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_compileoption_used(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 46))(__t__p0));\
	})

#define sqlite3_value_text16(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_value *))*(void**)(__base - 658))(__t__p0));\
	})

#define sqlite3_sourceid() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 34))());\
	})

#define sqlite3_threadsafe() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 58))());\
	})

#define sqlite3_create_collation_v2(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		int (* __t__p4)(void*,int,const void*,int,const void*) = __p4;\
		void (* __t__p5)(void*)  = __p5;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , void *, int (*)(void*,int,const void*,int,const void*), void (*)(void*) ))*(void**)(__base - 820))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define sqlite3_vfs_register(__p0, __p1) \
	({ \
		sqlite3_vfs * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_vfs *, int ))*(void**)(__base - 1000))(__t__p0, __t__p1));\
	})

#define sqlite3_file_control(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , void *))*(void**)(__base - 1048))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_column_table_name(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 478))(__t__p0, __t__p1));\
	})

#define sqlite3_finalize(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 586))(__t__p0));\
	})

#define sqlite3_column_decltype(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 502))(__t__p0, __t__p1));\
	})

#define sqlite3_column_double(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(sqlite3_stmt *, int ))*(void**)(__base - 544))(__t__p0, __t__p1));\
	})

#define sqlite3_value_text16be(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_value *))*(void**)(__base - 670))(__t__p0));\
	})

#define sqlite3_collation_needed16(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void (* __t__p2)(void*,sqlite3*,int eTextRep,const void*)  = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, void *, void (*)(void*,sqlite3*,int eTextRep,const void*) ))*(void**)(__base - 838))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_db_readonly(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *))*(void**)(__base - 868))(__t__p0, __t__p1));\
	})

#define sqlite3_result_blob(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const void *, int , void (*)(void*)))*(void**)(__base - 718))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_bind_double(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , double ))*(void**)(__base - 376))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_result_text16(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const void *, int , void (*)(void*)))*(void**)(__base - 784))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_limit(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int , int ))*(void**)(__base - 322))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_bind_zeroblob(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , int ))*(void**)(__base - 418))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_free_table(__p0) \
	({ \
		char ** __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(char **))*(void**)(__base - 178))(__t__p0));\
	})

#define sqlite3_mutex_try(__p0) \
	({ \
		sqlite3_mutex * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_mutex *))*(void**)(__base - 1030))(__t__p0));\
	})

#define sqlite3_enable_shared_cache(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 898))(__t__p0));\
	})

#define sqlite3_column_database_name16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 472))(__t__p0, __t__p1));\
	})

#define sqlite3_value_double(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(sqlite3_value *))*(void**)(__base - 634))(__t__p0));\
	})

#define sqlite3_next_stmt(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		sqlite3_stmt * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_stmt *(*)(sqlite3 *, sqlite3_stmt *))*(void**)(__base - 874))(__t__p0, __t__p1));\
	})

#define sqlite3_value_int64(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(sqlite3_value *))*(void**)(__base - 646))(__t__p0));\
	})

#define sqlite3_column_int(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int ))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})

#define sqlite3_user_data(__p0) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3_context *))*(void**)(__base - 694))(__t__p0));\
	})

#define sqlite3_sql(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *))*(void**)(__base - 352))(__t__p0));\
	})

#define sqlite3_vlog(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , const char *, va_list ))*(void**)(__base - 1126))(__t__p0, __t__p1, __p2));\
	})

#define sqlite3_column_name(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 454))(__t__p0, __t__p1));\
	})

#define sqlite3_blob_read(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_blob * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_blob *, void *, int , int ))*(void**)(__base - 982))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_table_column_metadata(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		char const ** __t__p4 = __p4;\
		char const ** __t__p5 = __p5;\
		int * __t__p6 = __p6;\
		int * __t__p7 = __p7;\
		int * __t__p8 = __p8;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, const char *, const char *, char const **, char const **, int *, int *, int *))*(void**)(__base - 922))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define sqlite3_complete(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 148))(__t__p0));\
	})

#define sqlite3_value_bytes(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_value *))*(void**)(__base - 622))(__t__p0));\
	})

#define sqlite3_result_double(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, double ))*(void**)(__base - 724))(__t__p0, __t__p1));\
	})

#define sqlite3_open16(__p0, __p1) \
	({ \
		const void * __t__p0 = __p0;\
		sqlite3 ** __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const void *, sqlite3 **))*(void**)(__base - 262))(__t__p0, __t__p1));\
	})

#define sqlite3_result_int(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, int ))*(void**)(__base - 760))(__t__p0, __t__p1));\
	})

#define sqlite3_column_origin_name16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 496))(__t__p0, __t__p1));\
	})

#define sqlite3_blob_write(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_blob * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_blob *, const void *, int , int ))*(void**)(__base - 988))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_close_v2(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 70))(__t__p0));\
	})

#define sqlite3_os_end() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 100))());\
	})

#define sqlite3_result_zeroblob(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, int ))*(void**)(__base - 808))(__t__p0, __t__p1));\
	})

#define sqlite3_prepare_v2(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		sqlite3_stmt ** __t__p3 = __p3;\
		const char ** __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , sqlite3_stmt **, const char **))*(void**)(__base - 334))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_blob_bytes(__p0) \
	({ \
		sqlite3_blob * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_blob *))*(void**)(__base - 976))(__t__p0));\
	})

#define sqlite3_mutex_free(__p0) \
	({ \
		sqlite3_mutex * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_mutex *))*(void**)(__base - 1018))(__t__p0));\
	})

#define sqlite3_get_auxdata(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3_context *, int ))*(void**)(__base - 706))(__t__p0, __t__p1));\
	})

#define sqlite3_set_authorizer(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int (* __t__p1)(void*,int,const char*,const char*,const char*,const char*) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int (*)(void*,int,const char*,const char*,const char*,const char*), void *))*(void**)(__base - 232))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_bind_int(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , int ))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_set_auxdata(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		void * __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, int , void *, void (*)(void*)))*(void**)(__base - 712))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_complete16(__p0) \
	({ \
		const void * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const void *))*(void**)(__base - 154))(__t__p0));\
	})

#define sqlite3_column_name16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 460))(__t__p0, __t__p1));\
	})

#define sqlite3_context_db_handle(__p0) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3 *(*)(sqlite3_context *))*(void**)(__base - 700))(__t__p0));\
	})

#define sqlite3_vfs_unregister(__p0) \
	({ \
		sqlite3_vfs * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_vfs *))*(void**)(__base - 1006))(__t__p0));\
	})

#define sqlite3_errmsg(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3 *))*(void**)(__base - 304))(__t__p0));\
	})

#define sqlite3_create_collation16(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		int (* __t__p4)(void*,int,const void*,int,const void*)  = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const void *, int , void *, int (*)(void*,int,const void*,int,const void*) ))*(void**)(__base - 826))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_errcode(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 292))(__t__p0));\
	})

#define sqlite3_interrupt(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3 *))*(void**)(__base - 142))(__t__p0));\
	})

#define sqlite3_test_vcontrol(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , va_list ))*(void**)(__base - 1054))(__t__p0, __p1));\
	})

#define sqlite3_soft_heap_limit64(__p0) \
	({ \
		sqlite3_int64  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(sqlite3_int64 ))*(void**)(__base - 916))(__t__p0));\
	})

#define sqlite3_release_memory(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 904))(__t__p0));\
	})

#define sqlite3_mutex_alloc(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_mutex *(*)(int ))*(void**)(__base - 1012))(__t__p0));\
	})

#define sqlite3_bind_null(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int ))*(void**)(__base - 394))(__t__p0, __t__p1));\
	})

#define sqlite3_commit_hook(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int (* __t__p1)(void*) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, int (*)(void*), void *))*(void**)(__base - 880))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_create_collation(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		int (* __t__p4)(void*,int,const void*,int,const void*)  = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , void *, int (*)(void*,int,const void*,int,const void*) ))*(void**)(__base - 814))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_value_bytes16(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_value *))*(void**)(__base - 628))(__t__p0));\
	})

#define sqlite3_bind_int64(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		sqlite3_int64  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , sqlite3_int64 ))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_wal_hook(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int (* __t__p1)(void *,sqlite3*,const char*,int) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, int (*)(void *,sqlite3*,const char*,int), void *))*(void**)(__base - 1132))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_malloc(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(int ))*(void**)(__base - 196))(__t__p0));\
	})

#define sqlite3_bind_text(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void (* __t__p4)(void*) = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , const char *, int , void (*)(void*)))*(void**)(__base - 400))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_prepare(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		sqlite3_stmt ** __t__p3 = __p3;\
		const char ** __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , sqlite3_stmt **, const char **))*(void**)(__base - 328))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_vfs_find(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_vfs *(*)(const char *))*(void**)(__base - 994))(__t__p0));\
	})

#define sqlite3_total_changes(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 136))(__t__p0));\
	})

#define sqlite3_bind_value(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const sqlite3_value * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , const sqlite3_value *))*(void**)(__base - 412))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_last_insert_rowid(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(sqlite3 *))*(void**)(__base - 124))(__t__p0));\
	})

#define sqlite3_rollback_hook(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void (* __t__p1)(void *) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, void (*)(void *), void *))*(void**)(__base - 886))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_vmprintf(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(const char *, va_list ))*(void**)(__base - 184))(__t__p0, __p1));\
	})

#define sqlite3_value_text16le(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_value *))*(void**)(__base - 664))(__t__p0));\
	})

#define sqlite3_result_null(__p0) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *))*(void**)(__base - 772))(__t__p0));\
	})

#define sqlite3_blob_close(__p0) \
	({ \
		sqlite3_blob * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_blob *))*(void**)(__base - 970))(__t__p0));\
	})

#define sqlite3_status(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int *, int *, int ))*(void**)(__base - 1060))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_auto_extension(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void *))*(void**)(__base - 928))(__t__p0));\
	})

#define sqlite3_stricmp(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *))*(void**)(__base - 1114))(__t__p0, __t__p1));\
	})

#define sqlite3_result_error16(__p0, __p1, __p2) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const void *, int ))*(void**)(__base - 736))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_db_handle(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3 *(*)(sqlite3_stmt *))*(void**)(__base - 856))(__t__p0));\
	})

#define sqlite3_uri_int64(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		sqlite3_int64  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(const char *, const char *, sqlite3_int64 ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_exec(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int (* __t__p2)(void*,int,char**,char**) = __p2;\
		void * __t__p3 = __p3;\
		char ** __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int (*)(void*,int,char**,char**), void *, char **))*(void**)(__base - 76))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_column_type(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int ))*(void**)(__base - 574))(__t__p0, __t__p1));\
	})

#define sqlite3_result_error_nomem(__p0) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *))*(void**)(__base - 748))(__t__p0));\
	})

#define sqlite3_result_text(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const char *, int , void (*)(void*)))*(void**)(__base - 778))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_memory_used() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(void))*(void**)(__base - 214))());\
	})

#define sqlite3_reset(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 592))(__t__p0));\
	})

#define sqlite3_unlock_notify(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void (* __t__p1)(void **apArg, int nArg) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, void (*)(void **apArg, int nArg), void *))*(void**)(__base - 1108))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_db_release_memory(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 910))(__t__p0));\
	})

#define sqlite3_reset_auto_extension() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 934))());\
	})

#define sqlite3_column_blob(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 526))(__t__p0, __t__p1));\
	})

#define sqlite3_db_vconfig(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int , va_list ))*(void**)(__base - 112))(__t__p0, __t__p1, __p2));\
	})

#define sqlite3_bind_parameter_name(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 430))(__t__p0, __t__p1));\
	})

#define sqlite3_column_int64(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(sqlite3_stmt *, int ))*(void**)(__base - 556))(__t__p0, __t__p1));\
	})

#define sqlite3_column_decltype16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 508))(__t__p0, __t__p1));\
	})

#define sqlite3_overload_function(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int ))*(void**)(__base - 958))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_value_type(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_value *))*(void**)(__base - 676))(__t__p0));\
	})

#define sqlite3_os_init() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 94))());\
	})

#define sqlite3_column_value(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_value *(*)(sqlite3_stmt *, int ))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})

#define sqlite3_extended_result_codes(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int ))*(void**)(__base - 118))(__t__p0, __t__p1));\
	})

#define sqlite3_column_bytes(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int ))*(void**)(__base - 532))(__t__p0, __t__p1));\
	})

#define sqlite3_value_int(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_value *))*(void**)(__base - 640))(__t__p0));\
	})

#define sqlite3_backup_init(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		sqlite3 * __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_backup *(*)(sqlite3 *, const char *, sqlite3 *, const char *))*(void**)(__base - 1078))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_value_blob(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_value *))*(void**)(__base - 616))(__t__p0));\
	})

#define sqlite3_shutdown() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 88))());\
	})

#define sqlite3_libversion() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 28))());\
	})

#define sqlite3_backup_remaining(__p0) \
	({ \
		sqlite3_backup * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_backup *))*(void**)(__base - 1096))(__t__p0));\
	})

#define sqlite3_column_database_name(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 466))(__t__p0, __t__p1));\
	})

#define sqlite3_mutex_leave(__p0) \
	({ \
		sqlite3_mutex * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_mutex *))*(void**)(__base - 1036))(__t__p0));\
	})

#define sqlite3_progress_handler(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int (* __t__p2)(void*) = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3 *, int , int (*)(void*), void *))*(void**)(__base - 250))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_db_mutex(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_mutex *(*)(sqlite3 *))*(void**)(__base - 1042))(__t__p0));\
	})

#define sqlite3_wal_checkpoint(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *))*(void**)(__base - 1144))(__t__p0, __t__p1));\
	})

#define sqlite3_create_module(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const sqlite3_module * __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, const sqlite3_module *, void *))*(void**)(__base - 940))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_bind_parameter_count(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 424))(__t__p0));\
	})

#define sqlite3_stmt_readonly(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 358))(__t__p0));\
	})

#define sqlite3_get_table(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		char *** __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		char ** __t__p5 = __p5;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, char ***, int *, int *, char **))*(void**)(__base - 172))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define sqlite3_result_text16be(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const void *, int , void (*)(void*)))*(void**)(__base - 796))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_sleep(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 844))(__t__p0));\
	})

#define sqlite3_column_origin_name(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 490))(__t__p0, __t__p1));\
	})

#define sqlite3_get_autocommit(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 850))(__t__p0));\
	})

#define sqlite3_trace(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void (* __t__p1)(void*,const char*) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, void (*)(void*,const char*), void *))*(void**)(__base - 238))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_step(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 514))(__t__p0));\
	})

#define sqlite3_wal_checkpoint_v2(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , int *, int *))*(void**)(__base - 1150))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_blob_open(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		sqlite3_int64  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		sqlite3_blob ** __t__p6 = __p6;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, const char *, const char *, sqlite3_int64 , int , sqlite3_blob **))*(void**)(__base - 964))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define sqlite3_realloc(__p0, __p1) \
	({ \
		void * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void *, int ))*(void**)(__base - 202))(__t__p0, __t__p1));\
	})

#define sqlite3_uri_parameter(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const char *, const char *))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})

#define sqlite3_profile(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void (* __t__p1)(void*,const char*,sqlite3_uint64) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, void (*)(void*,const char*,sqlite3_uint64), void *))*(void**)(__base - 244))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_stmt_status(__p0, __p1, __p2) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , int ))*(void**)(__base - 1072))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_randomness(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int , void *))*(void**)(__base - 226))(__t__p0, __t__p1));\
	})

#define sqlite3_vconfig(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , va_list ))*(void**)(__base - 106))(__t__p0, __p1));\
	})

#define sqlite3_value_numeric_type(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_value *))*(void**)(__base - 682))(__t__p0));\
	})

#define sqlite3_bind_parameter_index(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, const char *))*(void**)(__base - 436))(__t__p0, __t__p1));\
	})

#define sqlite3_db_filename(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(sqlite3 *, const char *))*(void**)(__base - 862))(__t__p0, __t__p1));\
	})

#define sqlite3_libversion_number() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 40))());\
	})

#define sqlite3_column_count(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 448))(__t__p0));\
	})

#define sqlite3_initialize() \
	({ \
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 82))());\
	})

#define sqlite3_wal_autocheckpoint(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int ))*(void**)(__base - 1138))(__t__p0, __t__p1));\
	})

#define sqlite3_extended_errcode(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 298))(__t__p0));\
	})

#define sqlite3_vsnprintf(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((char *(*)(int , char *, const char *, va_list ))*(void**)(__base - 190))(__t__p0, __t__p1, __t__p2, __p3));\
	})

#define sqlite3_mutex_enter(__p0) \
	({ \
		sqlite3_mutex * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_mutex *))*(void**)(__base - 1024))(__t__p0));\
	})

#define sqlite3_vtab_on_conflict(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 1162))(__t__p0));\
	})

#define sqlite3_result_error_code(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, int ))*(void**)(__base - 754))(__t__p0, __t__p1));\
	})

#define sqlite3_declare_vtab(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *))*(void**)(__base - 952))(__t__p0, __t__p1));\
	})

#define sqlite3_errstr(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 316))(__t__p0));\
	})

#define sqlite3_stmt_busy(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 364))(__t__p0));\
	})

#define sqlite3_result_int64(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		sqlite3_int64  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, sqlite3_int64 ))*(void**)(__base - 766))(__t__p0, __t__p1));\
	})

#define sqlite3_prepare16_v2(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		sqlite3_stmt ** __t__p3 = __p3;\
		const void ** __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const void *, int , sqlite3_stmt **, const void **))*(void**)(__base - 346))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_column_text(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const unsigned char *(*)(sqlite3_stmt *, int ))*(void**)(__base - 562))(__t__p0, __t__p1));\
	})

#define sqlite3_vtab_vconfig(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int , va_list ))*(void**)(__base - 1156))(__t__p0, __t__p1, __p2));\
	})

#define sqlite3_result_value(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		sqlite3_value * __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, sqlite3_value *))*(void**)(__base - 802))(__t__p0, __t__p1));\
	})

#define sqlite3_result_error(__p0, __p1, __p2) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const char *, int ))*(void**)(__base - 730))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_busy_timeout(__p0, __p1) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int ))*(void**)(__base - 166))(__t__p0, __t__p1));\
	})

#define sqlite3_create_module_v2(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const sqlite3_module * __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		void (* __t__p4)(void*)       = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, const sqlite3_module *, void *, void (*)(void*)      ))*(void**)(__base - 946))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_column_table_name16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 484))(__t__p0, __t__p1));\
	})

#define sqlite3_data_count(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 520))(__t__p0));\
	})

#define sqlite3_prepare16(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		sqlite3_stmt ** __t__p3 = __p3;\
		const void ** __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const void *, int , sqlite3_stmt **, const void **))*(void**)(__base - 340))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_uri_boolean(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, int ))*(void**)(__base - 280))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_collation_needed(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		void (* __t__p2)(void*,sqlite3*,int eTextRep,const char*)  = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, void *, void (*)(void*,sqlite3*,int eTextRep,const char*) ))*(void**)(__base - 832))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_free(__p0) \
	({ \
		void * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void *))*(void**)(__base - 208))(__t__p0));\
	})

#define sqlite3_value_text(__p0) \
	({ \
		sqlite3_value * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const unsigned char *(*)(sqlite3_value *))*(void**)(__base - 652))(__t__p0));\
	})

#define sqlite3_backup_pagecount(__p0) \
	({ \
		sqlite3_backup * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_backup *))*(void**)(__base - 1102))(__t__p0));\
	})

#define sqlite3_db_status(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, int , int *, int *, int ))*(void**)(__base - 1066))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_clear_bindings(__p0) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *))*(void**)(__base - 442))(__t__p0));\
	})

#define sqlite3_errmsg16(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3 *))*(void**)(__base - 310))(__t__p0));\
	})

#define sqlite3_create_function(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		void (* __t__p5)(sqlite3_context*,int,sqlite3_value**) = __p5;\
		void (* __t__p6)(sqlite3_context*,int,sqlite3_value**) = __p6;\
		void (* __t__p7)(sqlite3_context*)  = __p7;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const char *, int , int , void *, void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*) ))*(void**)(__base - 598))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define sqlite3_changes(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 130))(__t__p0));\
	})

#define sqlite3_open_v2(__p0, __p1, __p2, __p3) \
	({ \
		const char * __t__p0 = __p0;\
		sqlite3 ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, sqlite3 **, int , const char *))*(void**)(__base - 268))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_aggregate_context(__p0, __p1) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3_context *, int ))*(void**)(__base - 688))(__t__p0, __t__p1));\
	})

#define sqlite3_strnicmp(__p0, __p1, __p2) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *, const char *, int ))*(void**)(__base - 1120))(__t__p0, __t__p1, __t__p2));\
	})

#define sqlite3_memory_highwater(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((sqlite3_int64 (*)(int ))*(void**)(__base - 220))(__t__p0));\
	})

#define sqlite3_column_bytes16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int ))*(void**)(__base - 538))(__t__p0, __t__p1));\
	})

#define sqlite3_result_text16le(__p0, __p1, __p2, __p3) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		void (* __t__p3)(void*) = __p3;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *, const void *, int , void (*)(void*)))*(void**)(__base - 790))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define sqlite3_column_text16(__p0, __p1) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const void *(*)(sqlite3_stmt *, int ))*(void**)(__base - 568))(__t__p0, __t__p1));\
	})

#define sqlite3_result_error_toobig(__p0) \
	({ \
		sqlite3_context * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(sqlite3_context *))*(void**)(__base - 742))(__t__p0));\
	})

#define sqlite3_compileoption_get(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 52))(__t__p0));\
	})

#define sqlite3_backup_step(__p0, __p1) \
	({ \
		sqlite3_backup * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_backup *, int ))*(void**)(__base - 1084))(__t__p0, __t__p1));\
	})

#define sqlite3_bind_text16(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void (* __t__p4)(void*) = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , const void *, int , void (*)(void*)))*(void**)(__base - 406))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_create_function16(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		void (* __t__p5)(sqlite3_context*,int,sqlite3_value**) = __p5;\
		void (* __t__p6)(sqlite3_context*,int,sqlite3_value**) = __p6;\
		void (* __t__p7)(sqlite3_context*)  = __p7;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *, const void *, int , int , void *, void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*,int,sqlite3_value**), void (*)(sqlite3_context*) ))*(void**)(__base - 604))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define sqlite3_close(__p0) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3 *))*(void**)(__base - 64))(__t__p0));\
	})

#define sqlite3_bind_blob(__p0, __p1, __p2, __p3, __p4) \
	({ \
		sqlite3_stmt * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const void * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		void (* __t__p4)(void*) = __p4;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_stmt *, int , const void *, int , void (*)(void*)))*(void**)(__base - 370))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define sqlite3_backup_finish(__p0) \
	({ \
		sqlite3_backup * __t__p0 = __p0;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(sqlite3_backup *))*(void**)(__base - 1090))(__t__p0));\
	})

#define sqlite3_update_hook(__p0, __p1, __p2) \
	({ \
		sqlite3 * __t__p0 = __p0;\
		void (* __t__p1)(void *,int ,char const *,char const *,sqlite3_int64) = __p1;\
		void * __t__p2 = __p2;\
		long __base = (long)(SQLITE_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(sqlite3 *, void (*)(void *,int ,char const *,char const *,sqlite3_int64), void *))*(void**)(__base - 892))(__t__p0, __t__p1, __t__p2));\
	})

#endif /* !_PPCINLINE_SQLITE_H */
