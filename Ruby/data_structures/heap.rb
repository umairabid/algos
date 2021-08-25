class Heap
  def initialize(fn)
    @heap = []
    @size = 0
    @fn = fn
  end

  def build(arr)
    @size = arr.count
    @heap = arr
    (@size/2).downto(0).each { |i| percolate_down i }
  end

  def add(vertex)
    @heap[@size] = vertex
    @size += 1
    
    percolate_up @size-1
  end

  def peek()
    @heap[0]
  end

  def pop()
    top = peek
    largest = @heap[@size-1]
    @heap[0] = largest
    @size -= 1
    @heap[@size] = nil
    percolate_down 0

    top
  end

  def to_a
    @heap
  end

  private

  def percolate_up(vertex_i)
    parent_i = parent vertex_i
    return if parent_i.nil?
    return if satisfies_heap? parent_i, vertex_i

    swap parent_i, vertex_i
    percolate_up parent_i
  end
  
  def percolate_down(vertex_i)
    left_i = left vertex_i
    right_i = right vertex_i
    return if satisfies_heap?(vertex_i, left_i) && satisfies_heap?(vertex_i, right_i)

    candidate = satisfies_heap?(left_i, right_i) ? left_i : right_i
    swap(vertex_i, candidate)
    percolate_down(candidate)
  end

  def satisfies_heap?(this, that)
    return true if that.nil?

    @fn.call(@heap[this], @heap[that])
  end

  def swap(this, that)
    temp = @heap[this]
    @heap[this] = @heap[that]
    @heap[that] = temp
  end

  def right(ix)
    right_i = (2 * ix) + 2
    right_i < @size ? right_i : nil
  end

  def left(ix)
    left_i = (2 * ix) + 1
    left_i < @size ? left_i : nil
  end

  def parent(ix)
    parent_i = ((ix - 1) / 2).floor
    parent_i >= 0 ? parent_i : nil
  end
end

heap = Heap.new( ->(x, y) { x[:weight] < y[:weight] })

#heap.percolate_up(2)
#puts heap.to_a

heap.build [
  {v: 10, weight: 10},
  {v: 11, weight: 11}, 
  {v: 5, weight: 5}, 
  {v: 3, weight: 3}, 
  {v: 4, weight: 4}
]
puts heap.to_a