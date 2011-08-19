ARGV.permutation.each do |p|
  ['+','-','*','/'].repeated_permutation(3).each do |o|
    s = "((%.0f %c %.0f) %c %.0f) %c %d" % p.zip(o).flatten.compact
    puts s if eval(s)==24
  end
end
