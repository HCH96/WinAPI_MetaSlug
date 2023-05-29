#include "global.h"

#include "Scene.h"
#include "Object.h"

Scene::Scene()
	: m_strName{}
	, m_arrObj{}
{
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
		}
	}
}


void Scene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<Object*>(m_arrObj[(UINT)_eTarget]);
}

void Scene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		DeleteGroup((GROUP_TYPE)i);
	}
}

void Scene::start()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->start();
		}
	}

}

void Scene::update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->update();
		}
	}
}

void Scene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->render(_dc);
		}
	}
}


