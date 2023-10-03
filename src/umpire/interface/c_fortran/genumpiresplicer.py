##############################################################################
# Copyright (c) 2016-23, Lawrence Livermore National Security, LLC and Umpire
# project contributors. See the COPYRIGHT file for details.
#
# SPDX-License-Identifier: (MIT)
##############################################################################
from __future__ import print_function

types = (
    ( 'int', 'integer(C_INT)' ),
    ( 'long', 'integer(C_LONG)' ),
    ( 'float', 'real(C_FLOAT)' ),
    ( 'double', 'real(C_DOUBLE)' )
)

maxdims = 3

def gen_bounds():
    print('')
    print('! splicer begin class.Allocator.type_bound_procedure_part')
    print('')
    for (name, _) in types:
        for dim in range(maxdims+1):
            print(f'procedure :: allocate_{name}_array_{dim+1}d => allocator_allocate_{name}_array_{dim+1}d')
            print(f'procedure :: deallocate_{name}_array_{dim+1}d => allocator_deallocate_{name}_array_{dim+1}d')
    print('generic, public :: allocate => &')
    for (name, _) in types:
        for dim in range(maxdims+1):
            print(f'    allocate_{name}_array_{dim+1}d, &')
    print('')
    print('generic, public :: deallocate => &')
    for (name, _) in types:
        for dim in range(maxdims+1):
            print(f'    deallocate_{name}_array_{dim+1}d, &')
    print('')
    print('! splicer end class.Allocator.type_bound_procedure_part')
    print('')

def gen_methods():
    print('! splicer begin class.Allocator.additional_functions')
    print('')

    for (name, c_type) in types:
        for dim in range(maxdims+1):
            print("""
subroutine allocator_allocate_{name}_array_{dim}d(this, array, dims)
      use iso_c_binding

      class(UmpireAllocator) :: this
      {c_type}, intent(inout), pointer, dimension({dim_string}) :: array

      integer(C_SIZE_T), dimension(:) :: dims

      type(C_PTR) :: data_ptr

      {c_type} :: size_type
      integer(C_SIZE_T) :: num_bytes

      num_bytes = product(dims) * sizeof(size_type)
      data_ptr = this%allocate_pointer(num_bytes)

      call c_f_pointer(data_ptr, array, dims)
end subroutine allocator_allocate_{name}_array_{dim}d

""".format(dim=dim+1, name=name, c_type=c_type, dim_string= ", ".join([":" for i in range(dim+1)])))

            print("""
subroutine allocator_deallocate_{name}_array_{dim}d(this, array)
      use iso_c_binding

      class(UmpireAllocator) :: this
      {c_type}, intent(inout), pointer, dimension({dim_string}) :: array

      type(C_PTR) :: data_ptr

      data_ptr = c_loc(array)

      call this%deallocate_pointer(data_ptr)
      nullify(array)
end subroutine allocator_deallocate_{name}_array_{dim}d

""".format(dim=dim+1, name=name, c_type=c_type, dim_string= ", ".join([":" for i in range(dim+1)])))
    print('! splicer end class.Allocator.additional_functions')

def gen_fortran():
    print('! Generated by genfumpiresplicer.py')
    print('')

    gen_bounds()
    gen_methods()

if __name__ == '__main__':
    gen_fortran()
