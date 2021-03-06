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
#include "qtypes.h"
#include "add_fld.h"
#include "auxil.h"
#include "dbauxil.h"
#include "is_tbl.h"
#include "del_tbl.h"
#include "aux_meta.h"
#include "meta_globals.h"

// START FUNC DECL
int
rename_tbl(
	char *old_tbl,
	char *new_tbl
	)
// STOP FUNC DECL
{
  int status = 0;
  int old_tbl_id, new_tbl_id;
  TBL_REC_TYPE old_tbl_rec, new_tbl_rec;
  //------------------------------------------------
  if ( ( new_tbl == NULL ) || ( *new_tbl == '\0' ) ) { go_BYE(-1); }
  if ( ( old_tbl == NULL ) || ( *old_tbl == '\0' ) ) { go_BYE(-1); }
  if ( strcmp(new_tbl, old_tbl) == 0 ) { go_BYE(-1); }
  //------------------------------------------------
  status = is_tbl(old_tbl, &old_tbl_id, &old_tbl_rec); cBYE(status);
  chk_range(old_tbl_id, 0, g_n_tbl);
  status = is_tbl(new_tbl, &new_tbl_id, &new_tbl_rec); cBYE(status);
  if ( new_tbl_id >= 0 ) { 
    status = del_tbl(NULL, new_tbl_id);
  }
  status = chk_tbl_name(new_tbl); cBYE(status);
  strcpy(g_tbls[old_tbl_id].name, new_tbl);
  //------------------------------------------------
 BYE:
  return(status);
}
