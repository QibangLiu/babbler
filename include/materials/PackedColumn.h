#pragma

#include "Material.h"

#include "LinearInterpolation.h"

/**
 * Computes the permeability of a porous medium made up of packed steel spheres of a specified
 * diameter in accordance with Pamuk and Ozdemir (2012). This also provides a specified dynamic
 * viscosity of the fluid in the medium.
 */

class PackedColumn : public Material
{
public:
  static InputParameters validParams();
  PackedColumn(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;
  const Real & _diameter;
  const Real & _input_viscosity;
  /// This object interpolates permeability (m^2) based on the diameter (mm)
  LinearInterpolation _permeability_interpolation;

  ADMaterialProperty<Real> & _permeability;
  ADMaterialProperty<Real> & _viscosity;

private:
  /* data */
};
