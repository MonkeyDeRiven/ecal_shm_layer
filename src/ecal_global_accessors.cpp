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

#include "ecal_global_accessors.h"


namespace eCAL
{
    /*
  CMemFileThreadPool* g_memfile_pool()
  {
    if (g_globals() == nullptr) return(nullptr);
    return(g_globals()->memfile_pool().get());
  }
     */

  CMemFileMap* g_memfile_map()
  {
    if (g_globals() == nullptr) return(nullptr);
    return(g_globals()->memfile_map().get());
  }
}
