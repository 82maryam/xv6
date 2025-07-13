#include "types.h"
#include "riscv.h"
#include "custom_logger.h"
#include "defs.h"

enum log_levels{INFO, WARN, ERROR}; 

void log_message(int level, const char *message) {

    switch (level){
    case INFO:
        printf("\"INFO- %s\"\n\n", message); 
        break;
    case WARN:
        printf("\"WARNING- %s\"\n\n", message); 
        break; 
    case ERROR:
        printf("\"ERROR- %s\"\n\n", message); 
        break; 
    default:
        printf("\"UNKOWN LOG LEVEL!"); 
    }
}