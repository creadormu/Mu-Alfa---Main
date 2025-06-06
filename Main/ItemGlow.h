#pragma once

#define MAX_JCRENDER_MESH	1000

struct ITEM_RENDER_MESH
{
	int ItemIndex;
	float ColorR;
	float ColorG;
	float ColorB;
};

class JCRenderMesh
{
public:
	JCRenderMesh();
	virtual ~JCRenderMesh();
	void Init();
	void Load(ITEM_RENDER_MESH * info);
	int JCSearch( int JCItemID, int JCModelObject, int JCModelEffect, int JCRegistro );
public:
	std::vector<ITEM_RENDER_MESH> m_JCRenderMesh;

}; extern JCRenderMesh JCRender;