project('text2svg', 'c',
  version : '0.1.0',
  default_options : ['warning_level=3'])

pangocairo = dependency('pangocairo', required: true)

executable('test-svg',
           'test-svg.c',
		  dependencies: [pangocairo],
		  install : true)
