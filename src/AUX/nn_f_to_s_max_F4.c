/*
© [2013] LinkedIn Corp. All rights reserved.
Licensed under the Apache License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may obtain
a copy of the License at  http://www.apache.org/licenses/LICENSE-2.0
 
Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an "AS IS"
BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied.
*/
// START FUNC DECL
void
nn_f_to_s_max_F4(
    float *X,
    char *nn_X,
    long long nX,
    long long *ptr_cnt,
    float *ptr_rslt
    )
// STOP FUNC DECL
{
  float rslt = *ptr_rslt;
  long long cnt = *ptr_cnt;
  for ( long long i = 0; i < nX; i++ ) { 
    if ( nn_X[i] == 0 ) { continue; }
    if ( X[i] > *ptr_rslt ) {
      rslt = X[i];
    }
    cnt++;
  }
  *ptr_rslt = rslt;
  *ptr_cnt  = cnt;
}
