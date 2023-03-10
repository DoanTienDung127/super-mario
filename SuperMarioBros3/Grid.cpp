#include "Grid.h"
#include "GridConst.h"
#include "Const.h"
using namespace std;
CGrid::CGrid()
{
}

CGrid::CGrid(D3DXVECTOR2 mapSize)
{
	columns = (int)ceil((float)mapSize.x / (float)CELL_WIDTH);
	rows = (int)ceil((float)mapSize.y / (float)CELL_WIDTH);

	// Khởi tạo cells
	for (int i = 0; i < columns; i++)
	{
		auto column = std::vector<CCell*>();
		for(int j = 0; j < rows ; j++)
		{
			column.push_back(new CCell(Index({ i, j })));
		}
		cells.push_back(column);
	}
}

void CGrid::Insert(CGameObject* gameObject)
{
	if (gameObject == NULL)
		return;
	auto cell = GetCell(gameObject->GetIndex());
	cell->AddObject(gameObject);
}

void CGrid::Remove(CGameObject* gameObject)
{
	if (gameObject == NULL)
		return;
	auto cell = GetCell(gameObject->GetIndex());
	cell->RemoveObject(gameObject);
}

void CGrid::Move(D3DXVECTOR2 oldPosition, CGameObject* gameObject)
{
	if (gameObject == NULL)
		return;
	auto oldCell = gameObject->GetIndex();
	auto newCell = GetCellIndexByPosition(gameObject->GetPosition());
	if (oldCell.x != newCell.x || oldCell.y != newCell.y)
	{
		if (oldCell.x >= 0 && oldCell.x <= columns - 1
			&& oldCell.y >= 0 && oldCell.y <= rows - 1)
		{
			auto cell = GetCell(oldCell);
			cell->RemoveObject(gameObject);
		}
		gameObject->SetIndex(newCell);
		Insert(gameObject);
	}
}

std::vector <CCell*>  CGrid::FindActiveCells(CCamera* camera)
{
	activeCells.clear();
	auto viewport = camera->GetPositionCam();
	auto width = camera->GetWidthCam();
	auto height = camera->GetHeightCam();

	int startCellX = (int)(viewport.x / (float)CELL_WIDTH);
	int startCellY = (int)(viewport.y / (float)CELL_HEIGHT);
	int endCellX =	(int)( (viewport.x + width) / (float)CELL_WIDTH );
	int endCellY = (int)( (viewport.y + height) / (float)CELL_HEIGHT );

	for (int i = startCellX -1 ; i <= endCellX ; i++)
	{
		if (i < 0 || i > columns) continue;
		for (int j = startCellY -1 ; j <= endCellY ; j++)
		{
			if (j < 0 || j > rows) continue;
			auto cell = GetCell(Index({i, j}));
			activeCells.push_back(cell);
		}
	}
	return activeCells;
}

std::vector <CGameObject*>  CGrid::FindActiveGameObjects(CCamera* camera)
{
	vector<CGameObject*> activeObjects;
	for (auto activeCell : activeCells)
	{
		for (auto gameObject : activeCell->GetListGameObject())
		{
			activeObjects.push_back(gameObject);
		}
	}
	return activeObjects;
}

RECT CGrid::GetRectByPosition(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	RECT rect;
	rect.left = (int)pos.x / CELL_WIDTH;
	rect.right = (int)(pos.x + size.x) / CELL_WIDTH;
	rect.top = (int)pos.y / CELL_HEIGHT;
	rect.bottom = (int)(pos.y + size.y) / CELL_HEIGHT;
	return rect;
}

Index CGrid::GetCellIndexByPosition(D3DXVECTOR2 pos)
{
	return { (int) (pos.x / CELL_WIDTH), (int) (pos.y / CELL_HEIGHT) };
}

CCell* CGrid::GetCell(Index index)
{
	if (index.x < 0)
		index.x = 0;
	if (index.x > columns - 1)
		index.x = columns - 1;

	if (index.y < 0)
		index.y = 0;
	if (index.y > rows - 1)
		index.y = rows - 1;
	return cells.at(index.x).at(index.y); // IMPORTANT
}

CCell* CGrid::GetCell(D3DXVECTOR2 position)
{
	auto index = GetCellIndexByPosition(position);
	return GetCell(index);
}

CGrid::~CGrid()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			delete cells.at(i).at(j);
		}
	}
	cells.clear();
}
