#include "amplpch.h"
#include "Amapola/Layers/LayerStack.h"

namespace Amapola
{
	LayerStack::LayerStack()
	{
		m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}
	
	void LayerStack::PushLayer(Layer* layer)
	{
		// A layer is always pushed before the overlays, at the end of "the first part of the list"
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}
	
	void LayerStack::PushOverlay(Layer* overlay)
	{
		// An overlay is always pushed at the very end ("second part of the list")
		m_Layers.emplace_back(overlay);
	}
	
	void LayerStack::PopLayer(Layer* layer)
	{
		auto i = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (i != m_Layers.end())
		{
			m_Layers.erase(i);
			m_LayerInsertIndex--;
		}
	}
	
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto i = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (i != m_Layers.end())
			m_Layers.erase(i);
	}
}
