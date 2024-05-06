/*
 * System.cpp
 *
 *  Created on: 8 de abr. de 2024
 *      Author: juan
 */

#include "../../include/system/SysInfo.h"

const string SysInfo::author = "Grupo M-01";
const string SysInfo::date = "2024, Abr";
const string SysInfo::department = "Faculdade de Tecnologia - Limeira/SP";
const string SysInfo::institution = "Universidade Estadual de Campinas (Unicamp)";
const string SysInfo::systemName = "College Management System 2024 C++";
const string SysInfo::version = "0.01 alfa";

const string& SysInfo::getAuthor()
{
	return author;
}

const string& SysInfo::getDate()
{
	return date;
}

const string& SysInfo::getDepartment()
{
	return department;
}

const string& SysInfo::getInstitution()
{
	return institution;
}

const string& SysInfo::getSystemName()
{
	return systemName;
}

const string& SysInfo::getVersion()
{
	return version;
}

const string SysInfo::getFullVersion()
{
	return systemName + " | Ver. " + version + " (" + date + ")";
}

