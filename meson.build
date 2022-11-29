project('text2svg', 'c',
  version : '0.1.0',
  default_options: [
    'default_library=static',
    'warning_level=3',
    'buildtype=release',
    'wrap_mode=nopromote',
    'cairo:tee=enabled',
    'cairo:tests=disabled', # We don't need tests
    'pango:cairo=enabled',
  ],
)

subproject('cairo')
subproject('pango')
pangocairo = dependency('pangocairo', required: true)

executable('test-svg',
           'test-svg.c',
		  dependencies: [pangocairo],
		  install : true)
