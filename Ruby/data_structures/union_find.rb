class UnionFind
    attr_reader :hash

    def initialize
        @hash = {}
    end

    def count
        @hash.count
    end

    def find(n)
        parent = @hash[n]
        return parent if parent.nil?
        return n if parent < 0

        @hash[n] = find parent
        @hash[n]
    end

    def add(n)
        return unless find(n).nil?
        
        @hash[n] = -1
    end

    def connected?(x, y)
        find(x) == find(y)
    end

    def union(x, y)
        return if connected?(x, y)
        
        x = find x
        y = find y

        weight_x = @hash[x].abs
        weight_y = @hash[y].abs
        
        root = weight_x > weight_y ? x : y
        child = weight_x > weight_y ? y : x
        
        @hash[root] = @hash[root] - @hash[child].abs
        @hash[child] = root
    end
end
