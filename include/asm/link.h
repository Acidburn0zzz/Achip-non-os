#define FUNC_NAME(X)	X
#define FUNC_NAME_LABEL(X)	X:

#define ALIGN .align 4

#define LFUNC(name)			\
	ALIGN; 					\
	FUNC_NAME_LABEL(name)

#define FUNC(name) 			\
	.globl FUNC_NAME(name); \
	.type name, function ; \
	LFUNC(name)

#define END(name) 			\
    .size name, .-name

#define ENDFUNC(name)		\
	.type name STT_FUNC; 	\
	END(name)				\

