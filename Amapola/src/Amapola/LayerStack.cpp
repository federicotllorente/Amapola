#include "amplpch.h"
#include "LayerStack.h"

namespace Amapola
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}
	
	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer); // A layer is always pushed before the overlays, at the end of "the first part of the list"
	}
	
	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay); // An overlay is always pushed at the very end ("second part of the list")
	}
	
	void LayerStack::PopLayer(Layer* layer)
	{
		auto i = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (i != m_Layers.end())
		{
			m_Layers.erase(i);
			m_LayerInsert--;
		}
	}
	
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto i = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (i != m_Layers.end())
			m_Layers.erase(i);
	}
}
