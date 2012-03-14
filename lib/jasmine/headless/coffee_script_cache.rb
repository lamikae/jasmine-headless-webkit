require 'coffee_script'
require 'digest/sha1'
require 'fileutils'

module Jasmine
  module Headless
    class CoffeeScriptCache < CacheableAction
      class << self
        def cache_type
          "coffee_script"
        end
      end

      def action
        # .coffee.erb templates are flattened without actual erb rendering
        if file[/.coffee.erb$/]
          Jasmine::Headless.warn("[%s] %s: %s" % [ "Erb File".color(:magenta), file.color(:yellow), "flatten".color(:white) ])
        end
        CoffeeScript.compile(File.read(file))
      end
    end
  end
end

