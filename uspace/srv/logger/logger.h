/*
 * Copyright (c) 2012 Vojtech Horky
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @addtogroup logger
 * @{
 */
/** @file Common logger service definitions.
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <adt/list.h>
#include <adt/prodcons.h>
#include <io/log.h>
#include <bool.h>
#include <fibril_synch.h>

#define NAME "logger"
#define MAX_NAMESPACE_LENGTH 256
#define LOG_LEVEL_USE_DEFAULT (LVL_LIMIT + 1)

typedef struct logging_namespace logging_namespace_t;

logging_namespace_t *namespace_create(const char *);
const char *namespace_get_name(logging_namespace_t *);
void namespace_destroy(logging_namespace_t *);
logging_namespace_t *namespace_writer_attach(const char *);
void namespace_writer_detach(logging_namespace_t *);

int namespace_change_level(logging_namespace_t *, log_level_t);

void namespace_wait_for_reader_change(logging_namespace_t *, bool *);
bool namespace_has_reader(logging_namespace_t *, sysarg_t, log_level_t);
void namespace_add_message(logging_namespace_t *, const char *, sysarg_t, log_level_t);

int namespace_create_context(logging_namespace_t *, const char *);

log_level_t get_default_logging_level(void);
int set_default_logging_level(log_level_t);

#endif

/** @}
 */
