#pragma once
#include <memory>


#include "widgetscontainer.h"
#include "widgetsrepository.h"

namespace asclepios::gui
{
	class WidgetsController
	{
	public:
		WidgetsController();
		~WidgetsController() = default;


		//getters
		[[nodiscard]] WidgetsRepository* getWidgetsRepository() const { return m_widgetsRepository.get(); }
		[[nodiscard]] WidgetsContainer* getWidgetsContainer() const { return m_widgetsContainer.get(); }
		[[nodiscard]] TabWidget* getActiveWidget() const { return m_activeWidget; }

		void createWidgets(const WidgetsContainer::layouts& t_layout);

	private:
		std::unique_ptr<WidgetsRepository> m_widgetsRepository = {};
		std::unique_ptr<WidgetsContainer> m_widgetsContainer = {};
		TabWidget* m_activeWidget = {};


		void initData();
		void createRemoveWidgets(const std::size_t& t_nrWidgets) const;
		[[nodiscard]] TabWidget* createNewWidget() const;
		[[nodiscard]] std::size_t computeNumberWidgetsFromLayout(const WidgetsContainer::layouts& t_layout);
	};
}
