// A T L A S T
//
//  ATLast/atltypes.h
//
//  Derived from code designed and implemented 1990 by John Walker
//  and placed into the public domain by him.
//  Original at https://www.fourmilab.ch/atlast/atlast.html
//
//  Created by Michael Henderson on 6/19/14.
//  Changes Copyright (c) 2014 Michael D Henderson. All rights reserved.
//

#ifndef ATLast_atltypes_h
#define ATLast_atltypes_h

/*  Data types	*/

typedef long                 atl_int;               // Stack integer type
typedef double               atl_real;              // Real number type
typedef struct atl_statemark atl_statemark;
typedef void               (*codeptr)();            // Machine code pointer
typedef struct dw            dictword;
typedef long                 stackitem;
typedef dictword           **rstackitem;



/*  Internal state marker item	*/

struct atl_statemark {
    stackitem *mstack;		      /* Stack position marker */
    stackitem *mheap;		      /* Heap allocation marker */
    dictword ***mrstack;	      /* Return stack position marker */
    dictword *mdict;		      /* Dictionary marker */
};

/*  Dictionary word entry  */

struct dw {
    struct dw *wnext;	      /* Next word in dictionary */
    char *wname;		      /* Word name.  The first character is
                               actually the word flags, including
                               the (IMMEDIATE) bit. */
    codeptr wcode;		      /* Machine code implementation */
};

/*  Primitive definition table entry  */

struct primfcn {
    char *pname;
    codeptr pcode;
};



#endif
