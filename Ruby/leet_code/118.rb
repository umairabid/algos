# @param {Integer} num_rows
# @return {Integer[][]}
def generate(num_rows)
  rows = [[1]]
  last_row = [1]
  for i in 2..num_rows
      last_row = generate_next last_row
      rows.push last_row
  end
  rows
end

def generate_next(row)
  next_row = Array.new(row.length+1, 0)
  next_row[0] = row[0]
  next_row[next_row.length-1] = row[row.length-1]
  for i in 1...next_row.length-1
    next_row[i] = row[i] + row[i-1]
  end
  next_row
end