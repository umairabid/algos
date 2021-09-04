# @param {Integer[]} cost
# @return {Integer}

def min_cost_climbing_stairs(cost)
  step_costs = {}
  step_cost(cost, -1, step_costs)
end

def step_cost(costs, step, step_costs)
  return 0 if step > costs.length - 1
  return step_costs[step] unless step_costs[step] == nil
  cost_at_step = [
      step_cost(costs, step + 1, step_costs),
      step_cost(costs, step + 2, step_costs)
  ].min
  
  current_step_cost = step == -1 ? 0 : costs[step]
  cost = current_step_cost + cost_at_step
  step_costs[step] = cost
  cost
end