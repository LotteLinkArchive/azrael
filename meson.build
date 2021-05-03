project('azrael', 'c')

cc = meson.get_compiler('c')
xxhash_dep = cc.find_library('xxhash', required : true)

azrael_incdir = include_directories('include')
subdir('include')
subdir('src')
azrael_dep = declare_dependency(include_directories : azrael_incdir, link_with : azrael)
subdir('tests')
