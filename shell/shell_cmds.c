/** @weakgroup shell
 *  @{
 */
/**
 * @file
 * @brief shell commands
 *
 * Copyright 2020 Stanislav V. Vlasov <stanislav.v.v@gmail.com>
 *
 * command list see in #cmds[]
 */

#ifndef UNITTEST
    #include "FreeRTOS.h"
    #include "task.h"
    #include "hw.h"
#else
    #include <stddef.h>
#endif
#include "shell.h"
#include "shell_cmds.h"
#include "libs/strings_local.h"

/**
 * @brief send 'Hello World!!!' string as shell output
 * @param argv, argc -- any strings or none
 */
void shell_hello_cmd(char* argv[], uint16_t argc)
{
    (void)(argv);
    (void)(argc);
    shell_out_buffer_add("Hello world!!!\r\n");
}

// shell command, that need cmds[]
/**
 * @brief send list of available commands
 * @param argv, argc -- any strings or none
 */
void shell_ls_cmd(char* argv[], uint16_t argc)
{
    (void)(argv);
    (void)(argc);
    uint16_t i = 0;
    shell_out_buffer_add("\r\n-- commands --\r\n");
    while (cmds[i].cmd != NULL)
    {
        shell_out_buffer_add(cmds[i].cmd_str);
        shell_out_buffer_add("\r\n");
        i++;
    }
}

#ifdef UNITTEST

/**
 * @brief arguments test command
 * @param argv, argc -- any strings or none
 *
 * Send arguments count and its contents.
 *
 * This is reference procedure for argument processing.
 */
void args_cmd( char* argv[], uint16_t argc )
{
    uint16_t i;
    char num[6];
    shell_out_buffer_add("arguments count: ");
    itoa_u16(argc, num);
    shell_out_buffer_add(num);
    shell_out_buffer_add("\r\n");
    for (i = 0; i< argc; ++i)
    {
        shell_out_buffer_add("argument ");
        itoa_u16(i, num);
        shell_out_buffer_add(num);
        shell_out_buffer_add(": ");
        shell_out_buffer_add(argv[i]);
        shell_out_buffer_add("\r\n");
    }
}

#else // ifdef UNITTEST

/**
 * @brief show rtos heap usage
 * @param argv, argc - any may be given, none used
 *
 * @ingroup hwrtos_shell
 */
void shell_rtos_heap_cmd(char* argv[], uint16_t argc)
{
    (void)(argv);
    (void)(argc);
    HeapStats_t stats;
    char s[20] = "\0";
    shell_out_buffer_add("rtos heap stats:");
    vPortGetHeapStats(&stats);

    itoa_u16((uint16_t)stats.xAvailableHeapSpaceInBytes, s);
    shell_out_buffer_add("Avail bytes total: ");
    shell_out_buffer_add(s);
    shell_out_buffer_add("\r\n");

    itoa_u16((uint16_t)stats.xSizeOfLargestFreeBlockInBytes, s);
    shell_out_buffer_add("Largest free block in bytes: ");
    shell_out_buffer_add(s);
    shell_out_buffer_add("\r\n");

    itoa_u16((uint16_t)stats.xMinimumEverFreeBytesRemaining, s);
    shell_out_buffer_add("Min free bytes total: ");
    shell_out_buffer_add(s);
    shell_out_buffer_add("\r\n");
}


#endif  // ifdef UNITTEST

///@}
