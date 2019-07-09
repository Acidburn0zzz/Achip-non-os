.global _SP__vectors
_SP__vectors:
        LDR PC, =_RESET_handler
        LDR PC, =_UNDEF_INS_handler
        LDR PC, =_SWI_handler
        LDR PC, =_PREFE_ABORT_handler
        LDR PC, =_DATA_ABORT_handler
        LDR PC, =_NO_USED_handler
        LDR PC, =_IRQ_handler
        LDR PC, =_FIRQ_handler