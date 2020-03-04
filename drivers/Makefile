DIRS= flash  gpio spi i2c

# victor modified, change for stoping the process when error occurring
.PHONY:	all	clean $(DIRS)

all:$(DIRS)
$(DIRS):
ifeq (1, ${DEBUG})
		@$(MAKE) DEBUG=1 -C $@
else
		@$(MAKE) DEBUG=0 -C $@
endif
	
clean: 
ifeq (1, ${DEBUG})
		@$(foreach dir, $(DIRS), $(MAKE) DEBUG=1 -C $(dir) clean;)
else
		@$(foreach dir, $(DIRS), $(MAKE) DEBUG=0 -C $(dir) clean;)
endif
