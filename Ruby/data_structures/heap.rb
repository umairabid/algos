class Heap
  def initialize(array = [])
    @heap = array
    @id_index_map = {}
    @heap.each_with_index { |v, i| @id_index_map[v.id] = i}
    
    @size = @heap.length
    (@size/2).downto(0).each { |i| percolate_down(i) }
  end
  
  def find(id)
    index = @id_index_map[id]
    index ? @heap[index] : nil
  end
  
  def add(node)
    @heap[@size] = node
    @id_index_map[node.id] = @size
    @size += 1
    percolate_up @size-1
  end
  
  def increase_key(node)
    existing_index = @id_index_map[node.id]
    existing_node = @heap[existing_index]
    @heap[existing_index] = node
    percolate_up existing_index
  end
  
  def pop
    return if @size == 0
    node = @heap[0]
    swap(0, @size-1)
    @heap[@size-1] = nil
    percolate_down 0
    @size -= 1
    node
  end
  
  private
  
  def percolate_down(i)
    return if ( @heap[left(i)].nil? || @heap[i].satisfies_heap?(@heap[left(i)])
    ) and (@heap[right(i)].nil? || @heap[i].satisfies_heap?(@heap[right(i)]))
    
    candidate = @heap[left(i)].satisfies_heap?(@heap[right(i)]) ? left(i) : right(i)
    return if candidate >= @size
    swap(i, candidate)
    percolate_down(candidate)
  end
  
  def percolate_up(i)
    return if parent(i) < 0
    return if @heap[parent(i)].satisfies_heap?(@heap[i])
    
    p = parent(i)
    swap(p, i)
    percolate_up p
  end
  
  def swap(current, target)
    current_id = @heap[current].id
    target_id = @heap[target].id
    @heap[current], @heap[target] = @heap[target], @heap[current]
    @id_index_map[current_id], @id_index_map[target_id] = @id_index_map[target_id], @id_index_map[current_id]
  end
  
  def parent(i)
    (i - 1) / 2
  end
  
  def left(i)
    (2 * i) + 1
  end
  
  def right(i)
    (2 * i) + 2
  end
end
