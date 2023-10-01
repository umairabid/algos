class Trie
    TrieNode = Struct.new(:char, :children, :is_end)
    def initialize
        @root = TrieNode.new('', [], true)
    end
    
    def insert(word)
        node = @root
        word.split('').each do |c|
            child_node = node.children.find { |tn| tn.char == c }
            if child_node.nil?
                child_node = TrieNode.new(c, [], false)
                node.children.push child_node
                node = child_node
            else
                node = child_node
            end
        end
        node.is_end = true
    end
    
    def has_prefix?(prefix)
        node = @root
        prefix.split('').each do |c|
            node = node.children.find { |tn| tn.char == c }
            return false if node.nil?
        end
        true
    end
    
    def words
        all_words = []
        words_recursive(@root, '', all_words)
        all_words
    end
    
    def words_recursive(node, prefix, words)
        prefix += node.char
        words.push(prefix) if node.is_end
        node.children.each { |tn| words_recursive(tn, prefix, words) }
    end
end
