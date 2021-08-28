class Heap
  attr_accessor :index_map

  def initialize(opts = {})
    @heap = []
    @size = 0
    @comparator = opts.dig(:comparator) || ->(a, b) { a < b}
    @vertex_id = opts.dig(:vertex_id)
    @index_map = {}
  end

  def build(arr)
    @size = arr.count
    @heap = arr
    @heap.each_with_index { |vertex, index| update_index vertex, index }
    (@size/2).downto(0).each { |i| percolate_down i }
  end

  def add(vertex)
    @heap[@size] = vertex
    update_index vertex, @size
    @size += 1
    
    percolate_up @size-1
  end

  def peek()
    @heap[0]
  end

  def pop()
    largest = @heap[@size-1]

    top = peek
    remove_index top
    
    @heap[0] = largest
    update_index @heap[0], 0

    @size -= 1
    @heap[@size] = nil

    percolate_down 0

    top
  end

  def to_a
    @heap
  end

  def vertex_index(vertex)
    @index_map[vertex_identifier(vertex)]
  end

  def update_key(vertex, key)
    current = @heap[key]
    if @comparator.call(vertex, current)
      @heap[key] = vertex
      percolate_up(key)
    end
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

  def update_index(vertex, index)
    @index_map[vertex_identifier(vertex)] = index
  end

  def remove_index(vertex)
    @index_map.delete(vertex_identifier(vertex))
  end

  def vertex_identifier(vertex)
    @vertex_id ? vertex.dig(@vertex_id) : vertex
  end

  def satisfies_heap?(this, that)
    return true if that.nil?

    @comparator.call(@heap[this], @heap[that])
  end

  def swap(this, that)
    temp_vertex = @heap[this]
    temp_vertex_index = vertex_index temp_vertex
    
    update_index @heap[this], vertex_index(@heap[that])
    @heap[this] = @heap[that]
    
    update_index @heap[that], temp_vertex_index
    @heap[that] = temp_vertex
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
