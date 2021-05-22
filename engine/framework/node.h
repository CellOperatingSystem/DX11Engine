#pragma once
#include "slot.h"

class NodeGraph;

typedef size_t NodeID;

class NodeBase
{
	friend class NodeGraph;

	template<typename T>
	friend class Node;

private:
	inline static NodeID GID = 0;

	// unique id used by imnodes
	// set by node graph
	int uid;

protected:
	// node graph that manages this node
	// only set by node graph
	NodeGraph* pNodeGraph = nullptr;

	JSON data;

	std::vector<Slot> inputs;
	std::vector<Slot> outputs;

public:
	virtual ~NodeBase() = default;

	virtual NodeID GetID() const = 0;
	virtual std::string GetStringID() const = 0;

public:
	int GetUID() const { return uid; }

	virtual void InitializeSlots() = 0;
	virtual void Update(double deltaSeconds) = 0;
	void SupplyDependents();

	virtual JSON ToJson() const = 0;
	virtual void FromJson(const JSON& json) = 0;

	virtual void DrawWidget() = 0;
};

DECLARE_CRTP(Node, NodeID)