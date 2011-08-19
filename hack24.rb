ARGV.permutation.each do |p|
  ['+','-','*','/'].repeated_permutation(3).each do |o|
    s = "((%.0f %c %.0f) %c %.0f) %c %d" % p.zip(o).flatten.compact
    p.map(&:to_f).zip(o).flatten.compact.join ' ';
    puts s if eval(s)==24
  end
end
