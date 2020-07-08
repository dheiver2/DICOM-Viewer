#include "corecontroller.h"
#include <iostream>

asclepios::core::CoreController::CoreController()
{
	initData();
}

//-----------------------------------------------------------------------------
void asclepios::core::CoreController::readData(const std::string& t_filepath) const
{
	try
	{
		m_dicomReader->readFile(t_filepath);
		m_dicomReader->dataSetExists()
			? insertDataInRepo()
			: throw std::exception("File not supported");
	}
	catch (std::exception& ex)
	{
		//todo log exception
		std::cout << ex.what() << '\n';
	}
}

//-----------------------------------------------------------------------------
void asclepios::core::CoreController::initData()
{
	m_coreRepository = std::make_unique<CoreRepository>();
	m_dicomReader = std::make_unique<DicomReader>();
}

//-----------------------------------------------------------------------------
void asclepios::core::CoreController::insertDataInRepo() const
{
	m_coreRepository->addPatient(m_dicomReader->getReadPatient());
	m_coreRepository->addStudy(m_dicomReader->getReadStudy());
	m_coreRepository->addSeries(m_dicomReader->getReadSeries());
	m_coreRepository->addImage(m_dicomReader->getReadImage());
}
