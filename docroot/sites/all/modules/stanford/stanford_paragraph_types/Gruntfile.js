/**
 * @file
 */
module.exports = function(grunt) {

  // This is where we configure each task that we'd like to run.
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      // This is where we set up all the tasks we'd like grunt to watch for changes.
      images: {
        files: ['**/*.{png,jpg,gif}'],
        tasks: ['imagemin'],
        options: {
          spawn: false,
        }
      },
      vector: {
        files: ['**/*.svg'],
        tasks: ['svgmin'],
        options: {
          spawn: false,
        }
      },
      css: {
        files: ['**/*.scss'],
        tasks: ['sass'],
        options: {
          interrupt: true
        }
      },
      twig: {
        files: ['**/*.html.twig'],
        tasks: ['svgmin', 'imagemin', 'sass', 'drush:ccall']
      }
    },
    imagemin: {
      // This will optimize all of our images for the web.
      dynamic: {
        files: [{
          expand: true,
          cwd: 'img/source/',
          src: ['{,*/}*.{png,jpg,gif}' ],
          dest: 'img/optimized/'
        }]
      }
    },
    svgmin: {
      options: {
        plugins: [{
          removeViewBox: false
        }, {
          removeUselessStrokeAndFill: false
        }]
      },
      dist: {
        files: [{
          expand: true,
          cwd: 'img/source/',
          src: ['{,*/}*.svg' ],
          dest: 'img/optimized/'
        }]
      }
    },
    sass: {
      // This will compile all of our sass files
      // Additional configuration options can be found at https://github.com/sindresorhus/grunt-sass
      options: {
        includePaths: [
          "node_modules/bourbon/core",
          "node_modules/bourbon-neat/core",
          "node_modules/neat-omega",
          "node_modules"
        ],
        sourceMap: false,
        // This controls the compiled css and can be changed to nested, compact or compressed.
        outputStyle: 'expanded',
        precision: 10
      },
      dist: {
        files: {
          'css/stanford_paragraph_types.admin.css': 'scss/stanford_paragraph_types.admin.scss',
          'css/stanford_paragraph_types.p_buttons.css': 'scss/stanford_paragraph_types.p_buttons.scss',
          'css/stanford_paragraph_types.p_callout.css': 'scss/stanford_paragraph_types.p_callout.scss',
          'css/stanford_paragraph_types.p_cards.css': 'scss/stanford_paragraph_types.p_cards.scss',
          'css/stanford_paragraph_types.p_hero.css': 'scss/stanford_paragraph_types.p_hero.scss',
          'css/stanford_paragraph_types.p_icon.css': 'scss/stanford_paragraph_types.p_icon.scss',
          'css/stanford_paragraph_types.p_menu.css': 'scss/stanford_paragraph_types.p_menu.scss',
          'css/stanford_paragraph_types.p_section_header.css': 'scss/stanford_paragraph_types.p_section_header.scss',
          'css/stanford_paragraph_types.p_two_columns.css': 'scss/stanford_paragraph_types.p_two_columns.scss',
          'css/stanford_paragraph_types.p_wysiwyg.css': 'scss/stanford_paragraph_types.p_wysiwyg.scss',
          'css/stanford_paragraph_types.p_wysiwyg_simple.css': 'scss/stanford_paragraph_types.p_wysiwyg_simple.scss',
          'css/stanford_paragraph_types.css': 'scss/stanford_paragraph_types.scss'
        }
      }
    },
    drush: {
      ccall: {
        args: ['cache-rebuild', 'all']
      }
    },
    browserSync: {
      dev: {
        bsFiles: {
          src : [
            'css/**/*.css',
            'templates/**/*.twig',
            'img/optimized/**/*.{png,jpg,gif,svg}',
            'js/build/**/*.js',
            '*.theme'
          ]
        },
        options: {
          watchTask: true,
          // reloadDelay: 1000,
          // reloadDebounce: 500,
          reloadOnRestart: true,
          logConnections: true,
          injectChanges: false // Depends on enabling the link_css module
        }
      }
    },
    availabletasks: {
      tasks: {
        options: {
          filter: "include",
          tasks: [
            'browserSync', 'imagemin', 'sass', 'svgmin', 'watch', 'devmode'
          ]
        }
      }
    }
  });

  // This is where we tell Grunt we plan to use this plug-in.
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-imagemin');
  grunt.loadNpmTasks('grunt-svgmin');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-browser-sync');
  grunt.loadNpmTasks('grunt-available-tasks');
  grunt.loadNpmTasks('grunt-drush');

  // My tasks.
  grunt.registerTask('devmode', "Watch and BrowserSync all in one.", ['browserSync', 'watch']);

  // This is where we tell Grunt what to do when we type "grunt" into the terminal.
  // Note: if you'd like to run and of the tasks individually you can do so by typing 'grunt mytaskname' alternatively
  // you can type 'grunt watch' to automatically track your files for changes.
  grunt.registerTask('default', ['availabletasks']);
};
