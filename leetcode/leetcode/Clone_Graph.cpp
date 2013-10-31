/*
Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 

OJ's undirected graph serialization:
 Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph. 
We use # as a separator for each node, and , as a separator for each neighbor of the node.
 
As an example, consider the serialized graph {1,2#2#2}. 

The graph has a total of three nodes, and therefore contains three parts as separated by #.
 1.Connect node 0 to both nodes 1 and 2.
 2.Connect node 1 to node 2.
 3.Connect node 2 to node 2 (itself), thus forming a self-cycle.
 

Visually, the graph looks like the following: 
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include "stdafx.h"
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	struct NodeInfo {
		UndirectedGraphNode *p_node;
		bool cloned;
		NodeInfo(UndirectedGraphNode *m_p_node, bool m_cloned) : p_node(m_p_node), cloned(m_cloned) {};
	};

	unordered_map<int, NodeInfo*> all_nodes;

	UndirectedGraphNode *insertNewNode(UndirectedGraphNode *node) {   		
		UndirectedGraphNode *cloned_node = new UndirectedGraphNode(node->label);
		NodeInfo *cloned_node_info = new NodeInfo(cloned_node, false);
		all_nodes.insert(make_pair(cloned_node->label, cloned_node_info));

		return cloned_node;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {        		
		all_nodes.clear();

		UndirectedGraphNode *result_node = NULL;
		stack<UndirectedGraphNode *> waiting_nodes;
		if (node != NULL) {
			waiting_nodes.push(node);
			insertNewNode(node);
		}		

		while (!waiting_nodes.empty()) {
			auto dealing_node = waiting_nodes.top();
			waiting_nodes.pop();

			auto it_all_nodes = all_nodes.find(dealing_node->label);
			it_all_nodes->second->cloned = true;
			UndirectedGraphNode *cur_node = it_all_nodes->second->p_node;
			if (result_node == NULL) {
				result_node = cur_node;
			}

			for (auto it_d_n = dealing_node->neighbors.begin(); it_d_n != dealing_node->neighbors.end(); it_d_n++) {
				auto it_same_label = all_nodes.find((*it_d_n)->label);
				UndirectedGraphNode *neighbor;
				if (it_same_label == all_nodes.end()) {
					neighbor = insertNewNode(*it_d_n);
					waiting_nodes.push(*it_d_n);
				} else {
					neighbor = it_same_label->second->p_node;
				}
				cur_node->neighbors.push_back(neighbor);
			}
		}

		for (auto it_all_nodes = all_nodes.begin(); it_all_nodes != all_nodes.end(); it_all_nodes++) {
			delete it_all_nodes->second;
		}
		all_nodes.clear();

		return result_node;
    }
};
