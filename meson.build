project('reproducer646', 'c')


py = import('python').find_installation(pure: false)

# Copy all the .py files to the install dir, rather than using
# py.install_sources and needing to list them explicitly one by one
install_subdir('src/reproducer646', install_dir: py.get_install_dir())

subdir('src/reproducer646')
