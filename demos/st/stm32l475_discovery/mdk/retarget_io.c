/*-----------------------------------------------------------------------------
 * Name:    retarget_io.c
 * Purpose: Retarget I/O
 *-----------------------------------------------------------------------------*/
 
/* Copyright (c) 2013 - 2017 ARM LIMITED
 
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/
 
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <rt_sys.h>
 
 
/* IO device file handles. */
#define FH_STDIN    0x8001
#define FH_STDOUT   0x8002
#define FH_STDERR   0x8003
// User defined ...
 
/* Standard IO device name defines. */
const char __stdin_name[]  = ":STDIN";
const char __stdout_name[] = ":STDOUT";
const char __stderr_name[] = ":STDERR";
 
 
/**
  Defined in rt_sys.h, this function opens a file.
 
  The _sys_open() function is required by fopen() and freopen(). These
  functions in turn are required if any file input/output function is to
  be used.
  The openmode parameter is a bitmap whose bits mostly correspond directly to
  the ISO mode specification. Target-dependent extensions are possible, but
  freopen() must also be extended.
 
  \param[in] name     File name
  \param[in] openmode Mode specification bitmap
 
  \return    The return value is –1 if an error occurs.
*/
FILEHANDLE _sys_open (const char *name, int openmode) {
 
  if (name == NULL) {
    return (-1);
  }
 
  if (name[0] == ':') {
    if (strcmp(name, ":STDIN") == 0) {
      return (FH_STDIN);
    }
    if (strcmp(name, ":STDOUT") == 0) {
      return (FH_STDOUT);
    }
    if (strcmp(name, ":STDERR") == 0) {
      return (FH_STDERR);
    }
    return (-1);
  }
  return (-1);
}
 
 
/**
  Defined in rt_sys.h, this function closes a file previously opened
  with _sys_open().
  
  This function must be defined if any input/output function is to be used.
 
  \param[in] fh File handle
 
  \return    The return value is 0 if successful. A nonzero value indicates
             an error.
*/
int _sys_close (FILEHANDLE fh) {
 
  switch (fh) {
    case FH_STDIN:
      return (0);
    case FH_STDOUT:
      return (0);
    case FH_STDERR:
      return (0);
  }
 
  return (-1);
}
 
 
/**
  Defined in rt_sys.h, this function writes the contents of a buffer to a file
  previously opened with _sys_open().
 
  \note The mode parameter is here for historical reasons. It contains
        nothing useful and must be ignored.
 
  \param[in] fh   File handle
  \param[in] buf  Data buffer
  \param[in] len  Data length
  \param[in] mode Ignore this parameter
 
  \return    The return value is either:
             - a positive number representing the number of characters not
               written (so any nonzero return value denotes a failure of
               some sort)
             - a negative number indicating an error.
*/
int _sys_write (FILEHANDLE fh, const uint8_t *buf, uint32_t len, int mode) {
 
  switch (fh) {
    case FH_STDIN:
      return (-1);
    case FH_STDOUT:
      return (0);
    case FH_STDERR:
      return (0);
  }
 
  return (-1);
}
 
 
/**
  Defined in rt_sys.h, this function reads the contents of a file into a buffer.
 
  Reading up to and including the last byte of data does not turn on the EOF
  indicator. The EOF indicator is only reached when an attempt is made to read
  beyond the last byte of data. The target-independent code is capable of
  handling:
    - the EOF indicator being returned in the same read as the remaining bytes
      of data that precede the EOF
    - the EOF indicator being returned on its own after the remaining bytes of
      data have been returned in a previous read.
 
  \note The mode parameter is here for historical reasons. It contains
        nothing useful and must be ignored.
 
  \param[in] fh   File handle
  \param[in] buf  Data buffer
  \param[in] len  Data length
  \param[in] mode Ignore this parameter
 
  \return     The return value is one of the following:
              - The number of bytes not read (that is, len - result number of
                bytes were read).
              - An error indication.
              - An EOF indicator. The EOF indication involves the setting of
                0x80000000 in the normal result.
*/
int _sys_read (FILEHANDLE fh, uint8_t *buf, uint32_t len, int mode) {
 
  switch (fh) {
    case FH_STDIN:
      return ((int)(len | 0x80000000U));
    case FH_STDOUT:
      return (-1);
    case FH_STDERR:
      return (-1);
  }
 
  return (-1);
}
 
 
/**
  Defined in rt_sys.h, this function writes a character to the console. The
  console might have been redirected. You can use this function as a last
  resort error handling routine.
  
  The default implementation of this function uses semihosting.
  You can redefine this function, or __raise(), even if there is no other
  input/output. For example, it might write an error message to a log kept
  in nonvolatile memory.
 
  \param[in] ch character to write
*/
void _ttywrch (int ch) {
}
 
 
/**
  Defined in rt_sys.h, this function determines if a file handle identifies
  a terminal.
 
  When a file is connected to a terminal device, this function is used to
  provide unbuffered behavior by default (in the absence of a call to
  set(v)buf) and to prohibit seeking.
 
  \param[in] fh File handle
 
  \return    The return value is one of the following values:
             - 0:     There is no interactive device.
             - 1:     There is an interactive device.
             - other: An error occurred.
*/
int _sys_istty (FILEHANDLE fh) {
 
  switch (fh) {
    case FH_STDIN:
      return (1);
    case FH_STDOUT:
      return (1);
    case FH_STDERR:
      return (1);
  }
 
  return (0);
}
 
 
/**
  Defined in rt_sys.h, this function puts the file pointer at offset pos from
  the beginning of the file.
 
  This function sets the current read or write position to the new location pos
  relative to the start of the current file fh.
 
  \param[in] fh  File handle
  \param[in] pos File pointer offset
 
  \return    The result is:
             - non-negative if no error occurs
             - negative if an error occurs
*/
int _sys_seek (FILEHANDLE fh, long pos) {
  return (-1);
}
 
 
/**
  Defined in rt_sys.h, this function returns the current length of a file.
 
  This function is used by _sys_seek() to convert an offset relative to the
  end of a file into an offset relative to the beginning of the file.
  You do not have to define _sys_flen() if you do not intend to use fseek().
  If you retarget at system _sys_*() level, you must supply _sys_flen(),
  even if the underlying system directly supports seeking relative to the
  end of a file.
 
  \param[in] fh File handle
 
  \return    This function returns the current length of the file fh,
             or a negative error indicator.
*/
long _sys_flen (FILEHANDLE fh) {
  return (0);
}
 