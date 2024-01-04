/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

/**
 * @brief  eCAL core functions
**/

#pragma once
#include <atomic>
#include <string>
#include <vector>

#include <ecal/ecal_process_severity.h>
#include <ecal_globals.h>

// Forward declaration of global accessible classes
namespace eCAL
{
    class  CGlobals;
  class  CConfig;
  class  CTimeGate;
  //class  CMemFileThreadPool;
  class  CMemFileMap;

  // Declaration of getter functions for globally accessible variable instances
  CGlobals*               g_globals();
  CTimeGate*              g_timegate();
  //CMemFileThreadPool*     g_memfile_pool();
  CMemFileMap*            g_memfile_map();

  // declaration of globally accessible variables
  extern CGlobals*                     g_globals_ctx;

  extern eCAL_Process_eSeverity        g_process_severity;
  extern eCAL_Process_eSeverity_Level  g_process_severity_level;
}
