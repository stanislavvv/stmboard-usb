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

#ifndef SHELL_CMDS_H_
#define SHELL_CMDS_H_

#include <stdint.h>
#include "shell.h"
#include "config.h"

#include <stddef.h>

/**
 * @brief send 'Hello World!!!' string as shell output
 * @param argv, argc -- any strings or none
 */
void shell_hello_cmd(char* argv[], uint16_t argc);

/**
 * @brief send list of available commands
 * @param argv, argc -- any strings or none
 */
void shell_ls_cmd(char* argv[], uint16_t argc);


#ifdef UNITTEST

/**
 * @brief arguments test command
 * @param argv, argc -- any strings or none
 *
 * Send arguments count and its contents.
 *
 * This is reference procedure for argument processing.
 */
void args_cmd( char* argv[], uint16_t argc );

#else // ifdef UNITTEST

/**
 * @brief show rtos heap usage
 * @param argv, argc - any may be given, none used
 *
 * @ingroup hwrtos_shell
 */
void shell_rtos_heap_cmd(char* argv[], uint16_t argc);


#endif // ifdef UNITTEST


/// shell commands list
static shell_cmd_def_t cmds[] =
{
    {"ls",        shell_ls_cmd}, // show commands
#ifndef UNITTEST

  #if DEBUG==1
    // hardware and rtos related commands, can't be tested now
    {"free",      shell_rtos_heap_cmd}, // show rtos heap stats
  #endif // DEBUG

#else // UNITTEST

    {"args",      args_cmd},            // test command with args
    {"hello",     shell_hello_cmd},     // test command

#endif // UNITTEST
    {NULL, NULL}
};


#endif // SHELL_CMDS_H_

///@}
