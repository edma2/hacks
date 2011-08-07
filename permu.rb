#!/bin/ruby
# vim: set shiftwidth=2 softtabstop=2 :
#
# Generate valid permutations of a word
# Author: edma2
#
 
if ARGV.length == 0
  puts "Usage: #{$0} [SEQ]..."
  exit
end
# Generate lookup table
dict = {}
open('dict.txt') {|f| f.each {|word| dict[word.strip] = true}}
ARGV.each do |seq|
  # Keep track of used words
  used = {}
  (2 .. seq.size).each do |n|
    seq.split(//).permutation(n).each do |p|
      word = p.join
      if dict[word]
        used[word] = true
        dict.delete word 
      end
    end
  end
  puts used.keys.join("\n")
  dict.merge! used
end
