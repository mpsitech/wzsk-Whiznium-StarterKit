<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButClaimClick')"
						:value="1"
						:disabled="!statshr.ButClaimActive"
					>
						<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<v-checkbox
				class="my-1"
				v-model="contiac.ChkErg"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptErg"
			/>

			<v-slider
				class="my-1"
				v-model="contiac.SldLle"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptLle"
				:min="statshr.SldLleMin"
				:max="statshr.SldLleMax"
				:disabled="!statshr.SldLleActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldLle"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-slider
				class="my-1"
				v-model="contiac.SldLri"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptLri"
				:min="statshr.SldLriMin"
				:max="statshr.SldLriMax"
				:disabled="!statshr.SldLriActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldLri"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvLaser',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvLaser.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLlvLaserDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvLaser"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvLaserData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvLaserData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLlvLaser) this.contiac = dpcheng.ContIacWzskLlvLaser;
				if (dpcheng.ContInfWzskLlvLaser) this.continf = dpcheng.ContInfWzskLlvLaser;
				if (dpcheng.StatShrWzskLlvLaser) this.statshr = dpcheng.StatShrWzskLlvLaser;
				if (dpcheng.TagWzskLlvLaser) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvLaser);
					this.tag = dpcheng.TagWzskLlvLaser;
				}
				if (dpcheng.ContInfWzskLlvLaser) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLlvLaserData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvLaserData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			statshr: null,

			tag: null,

			contapp: {
				ButClaimOn: 0,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
