# Copyright 2018 Slightech Co., Ltd. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set_outdir(
  ARCHIVE ${OUT_DIR}/lib/${DIR_NAME}
  LIBRARY ${OUT_DIR}/lib/${DIR_NAME}
  RUNTIME ${OUT_DIR}/bin/${DIR_NAME}
)

## record

make_executable(record
  SRCS record.cc dataset.cc
  LINK_LIBS  mynteye_depth ${OpenCV_LIBS}
  DLL_SEARCH_PATHS ${MYNTEYE_DLL_SEARCH_PATHS}
)



##record_all
make_executable(record_all
  SRCS record_all.cc dataset.cc
  LINK_LIBS  mynteye_depth ${OpenCV_LIBS}
  DLL_SEARCH_PATHS ${MYNTEYE_DLL_SEARCH_PATHS}
)