ARGV.permutation.each{|p|['+','-','*','/'].repeated_permutation(3).each{|o|s=p.map(&:to_f).zip(o).flatten.compact.join ' ';puts s if eval(s)==24}}
