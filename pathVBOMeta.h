

#ifndef TEST_PATHVBOMETA_H
#define TEST_PATHVBOMETA_H

namespace OGlW {
    struct AppearanceSettings {
        glm::vec4 sea_ambient;
        glm::vec4 sea_diffuse;
        glm::vec4 sea_specular;
        float sea_shininess;
        glm::vec4 path_colors[static_cast<size_t>(USV::PathType::End)];
        GLVessels::AppearanceSettings vessels_colors{};
    };
}

class pathVBOMeta {
public:
    pathVBOMeta(size_t ptr, const USV::Path* path, size_t points_count, USV::PathType path_type) : ptr(ptr), path(
            path), points_count(points_count), type(path_type) {};

    size_t& Ptr() {
        return ptr;
    }

    const size_t& Ptr() const{
        return ptr;
    }

    void (const AppearanceSettings& appearance_settings) {
        const auto& color = appearance_settings.path_colors[static_cast<size_t>(type)];
        glVertexAttrib3f(3, color.x, color.y, color.z);
        glDrawArrays(GL_LINE_STRIP, (GLint) ptr, (GLsizei) points_count);
    }

private:
    size_t ptr;
    const USV::Path* path;
    size_t points_count;
    USV::PathType type;
};

#endif //TEST_PATHVBOMETA_H
