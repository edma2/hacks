ARGV.permutation.each do |p|
  ['+','-','*','/'].repeated_permutation(3).each do |o|
    s = "(((%d %c %d) %c %d) %c %d)" % p.map(&:to_f).zip(o).flatten.compact
    p.map(&:to_f).zip(o).flatten.compact.join ' ';
    puts s if eval(s)==24
  end
end
