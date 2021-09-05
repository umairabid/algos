# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  local_max = 0
  global_max = -1000000
  
  nums.each do |x|
      local_max = [x, local_max + x].max
      global_max = local_max if local_max > global_max
  end
  global_max
end