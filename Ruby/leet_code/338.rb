# @param {Integer} n
# @return {Integer[]}

=begin
if you start counting in binary nums
then for an even number n, the number is same as n/2
except the the most significant bit is shifted to left
e.g 2 => 010 and 4 => 100

also odd number m is also same as m-1 except with added least significant bit
e.g 2 => 010 4=> 100 5=>101

=end

def count_bits(n)
  output = [0]
  (1..n).to_a.map do |x|
      x % 2 == 0 ?
          output << output[x / 2] :
          output << (output[x / 2] + 1)
  end
  output
end