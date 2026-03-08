#pragma once
#ifndef GEODESY_GFX_MATERIAL_H
#define GEODESY_GFX_MATERIAL_H

#include <string>
#include <vector>

// #include "../io/file.h"
#include <geodesy/math.h>

#include <geodesy/gpu/image.h>
#include <geodesy/gpu/shader.h>

struct aiMaterial;

namespace geodesy::gfx {


	// A material describes the qualities of a surface, such as 
	// its roughness, its 
	class material {
	public:

		enum rendering_system : int {
			LEGACY,
			PBR,
			UNKNOWN
		};

		enum transparency : int {
			OPAQUE, 
			TRANSPARENT,
			TRANSLUCENT
		};

		// enum orm_packing : int {};

		struct uniform_data {
			alignas(4) int 								Transparency;
			
			alignas(4) float 							AlbedoVertexWeight;
			alignas(4) float 							AlbedoTextureWeight;
			alignas(4) int 								AlbedoTextureExists;
			alignas(4) float 							AlbedoConstantWeight;
			alignas(16) math::vec<float, 3> 			Albedo;

			alignas(4) float 							OpacityTextureWeight;
			alignas(4) int 								OpacityTextureExists;
			alignas(4) float 							OpacityConstantWeight;
			alignas(4) float 							Opacity;

			alignas(4) float 							RefractionIndexWeight;
			alignas(4) float 							RefractionIndex;

			alignas(4) float 							NormalVertexWeight;
			alignas(4) float 							NormalTextureWeight;
			alignas(4) int 								NormalTextureExists;

			alignas(4) int 								HeightTextureExists;
			alignas(4) float 							HeightScale;
			alignas(4) int 								HeightStepCount;

			alignas(4) float 							EmissiveTextureWeight;
			alignas(4) int 								EmissiveTextureExists;
			alignas(4) float 							EmissiveConstantWeight;
			alignas(16) math::vec<float, 3> 			Emissive;

			alignas(4) float 							AmbientOcclusionTextureWeight;
			alignas(4) int 								AmbientOcclusionTextureExists;
			alignas(4) float 							AmbientOcclusionConstantWeight;
			alignas(4) float 							AmbientOcclusion;

			alignas(4) float 							RoughnessTextureWeight;
			alignas(4) int 								RoughnessTextureExists;
			alignas(4) float 							RoughnessConstantWeight;
			alignas(4) float 							Roughness;

			alignas(4) float 							MetallicTextureWeight;
			alignas(4) int 								MetallicTextureExists;
			alignas(4) float 							MetallicConstantWeight;
			alignas(4) float 							Metallic;

			uniform_data();
		};

		std::string 											Name;					// Name of the material
		uniform_data 											UniformData;
		std::shared_ptr<gpu::buffer> 							UniformBuffer;			// Uniform Buffer for the Material
		std::map<std::string, std::shared_ptr<gpu::image>> 		Texture;				// Texture Maps of the Material

		material();
		// material(const aiMaterial* aMaterial, std::string aDirectory, io::file::manager* aFileManager);
		material(std::shared_ptr<gpu::context> aContext, gpu::image::create_info aCreateInfo, std::shared_ptr<material> aMaterial);
		~material();

		void update(double aDeltaTime);

	};

}

#endif // !GEODESY_GFX_MATERIAL_H
