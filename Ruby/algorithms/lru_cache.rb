class Node
  attr_accessor :next, :prev, :val, :key

  def initialize
    @val = nil
    @next = nil
    @prev = nil
    @key = nil
  end
end

class LRUCache

  def initialize(size)
    @head = Node.new
    @tail = Node.new
    @head.next = @tail
    @size = size
    @hash = {}
  end

  def get(key)
    return if @hash[key].nil?
    node = @hash[key]
    remove_node node
    add_node_with_head node
    node.val
  end

  def put(key, value)
    node = Node.newP
    node.val = value
    node.key = key
    if @hash[key]
      node = @hash[key]
      node.val = value
      remove_node node
    elsif @hash.length == @size
      evict_tail_node
    end
    
    add_node_with_head(node)
    @hash[key] = node
  end

  private

  def add_node_with_head(node)
    curr_head_next = @head.next
    @head.next = node
    node.prev = @head
    node.next = curr_head_next
    curr_head_next.prev = node
  end

  def evict_tail_node
    node = @tail.prev
    @hash.delete node.key
    remove_node node
  end

  def remove_node(node)
    prev = node.prev
    nxt = node.next
    prev.next = nxt
    nxt.prev = prev
  end
end

